/* --------------------------------------------------------
 *    File: breakout.cpp
 *  Author: Tyler MacPhee
 *   Class: CEN3031, Fall 2022
 * Purpose: breakout game code
 * -------------------------------------------------------- */
#include <iostream>
#include <cmath>
#include "breakout_defs.h"

// Function declarations (prototypes)
// --------------------------------------------------------
void setup(Ball &ball, MovingBlock &paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders &walls);
Direction processInput() ;
bool update(Direction &input, bool &started,
            Ball &ball, MovingBlock &paddle,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS],
            Borders walls, float delta);
void render(sf::RenderWindow &window, Ball ball, MovingBlock paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders walls, float delta);
bool doCollisionChecks(Ball &ball, MovingBlock& paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders walls);
bool collisionCheck(Ball* pBall, Block* pBlock);
int getCollisionPoint(Ball* pBall, Block* pBlock);
bool checkBlockCollision(Block moving, Block stationary);


/**
 * The main application
 * @return OS stats message (0=Success)
 */
void breakout(sf::RenderWindow &window) {

    // declare a ball variable and populate it in the center of the window
    Ball theBall;
    MovingBlock thePaddle;
    Borders theWalls;
    Brick theBricks[BRICK_ROWS][BRICK_COLUMNS];
    setup(theBall, thePaddle, theBricks, theWalls);


    // timing variables for the main game loop
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();
    sf::Time stopTime = startTime;
    float delta = 0.0;

    bool started = false;

    bool gameOver = false;
    while (!gameOver)
    {
        // calculate frame time
        stopTime = clock.getElapsedTime();
        delta += (stopTime.asMilliseconds() - startTime.asMilliseconds());
        startTime = stopTime;

        // process events
        sf::Event event;
        while (!gameOver && window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                gameOver = true;
        }

        // Process user input
        // ------------------------------------------------
        Direction userInput = processInput();
        if (userInput == Exit)
            gameOver = true;

        // Process Updates
        // ------------------------------------------------
        if (delta >= FRAME_RATE) {    // if we have made it at least a full frame time

            gameOver = update(userInput, started, theBall, thePaddle, theBricks, theWalls, delta);

            // subtract the frame-rate from the current frame-time
            // for each full frame covered by this update
            while (delta >= FRAME_RATE)
                delta -= FRAME_RATE;
        }

        // Render the window
        // ------------------------------------------------
        render(window, theBall, thePaddle, theBricks, theWalls, delta);

    } // end main game loop

    // game ending, close the graphics window
    window.close();
} // end main


/**
 * initialize game objects
 * @param ball - set ball position and size and zero velocity
 * @param paddle - player paddle
 * @param walls - set border walls
 */
void setup(Ball &ball, MovingBlock &paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders &walls) {

    // --- init border walls ---
    walls.leftWall.left = 0.0;
    walls.leftWall.top = 0.0;
    walls.leftWall.width = WALL_THICKNESS;
    walls.leftWall.height = WINDOW_HEIGHT;
    walls.leftWall.rectangle.setSize(sf::Vector2f(walls.leftWall.width, walls.leftWall.height));
    walls.leftWall.rectangle.setPosition(walls.leftWall.left, walls.leftWall.top);
    walls.leftWall.rectangle.setFillColor(WALL_COLOR);

    walls.topWall.left = 0.0;
    walls.topWall.top = 0.0;
    walls.topWall.width = WINDOW_WIDTH;
    walls.topWall.height = WALL_THICKNESS;
    walls.topWall.rectangle.setSize(sf::Vector2f(walls.topWall.width, walls.topWall.height));
    walls.topWall.rectangle.setPosition(walls.topWall.left, walls.topWall.top);
    walls.topWall.rectangle.setFillColor(WALL_COLOR);

    walls.rightWall.left = WINDOW_WIDTH - WALL_THICKNESS;
    walls.rightWall.top = 0.0;
    walls.rightWall.width = WALL_THICKNESS;
    walls.rightWall.height = WINDOW_HEIGHT;
    walls.rightWall.rectangle.setSize(sf::Vector2f(walls.rightWall.width, walls.rightWall.height));
    walls.rightWall.rectangle.setPosition(walls.rightWall.left, walls.rightWall.top);
    walls.rightWall.rectangle.setFillColor(WALL_COLOR);

    walls.bottomWall.left = 0.0;
    walls.bottomWall.top = WINDOW_HEIGHT - WALL_THICKNESS;
    walls.bottomWall.width = WINDOW_WIDTH;
    walls.bottomWall.height = WALL_THICKNESS;
    walls.bottomWall.rectangle.setSize(sf::Vector2f(walls.bottomWall.width, walls.bottomWall.height));
    walls.bottomWall.rectangle.setPosition(walls.bottomWall.left, walls.bottomWall.top);
    walls.bottomWall.rectangle.setFillColor(WALL_COLOR);

    // --- player paddle ---
    paddle.block.left = (WINDOW_WIDTH - PADDLE_WIDTH) / 2.0;
    paddle.block.top = (walls.bottomWall.top - 2 * PADDLE_THICKNESS);
    paddle.block.width = PADDLE_WIDTH;
    paddle.block.height = PADDLE_THICKNESS;
    paddle.block.color = PADDLE_COLOR;
    paddle.block.rectangle.setSize(sf::Vector2f(paddle.block.width, paddle.block.height));
    paddle.block.rectangle.setFillColor(paddle.block.color);
    paddle.velocityX = 0.0;
    paddle.velocityY = 0.0;

    // --- init ball ---
    ball.radius = BALL_RADIUS;
    ball.coordinateX = paddle.block.left + paddle.block.width / 2.0;
    ball.coordinateY = paddle.block.top - ball.radius - 1;
    ball.velocityX = 0.0;
    ball.velocityY = 0.0;
    ball.color = BALL_COLOR;

    // -- bricks ---
    float bricksTop = FIRST_BRICK;
    int score = 1;
    int speedAdjust = 0;
    Brick* pNext = &bricks[0][0]; // get pointer to 1st brick
    for (int row = 0; row < BRICK_ROWS; row++) {
        float bricksLeft = BRICKS_LEFT;

        for (int column = 0; column < BRICK_COLUMNS; column++) {
            // offset left/top by 1 pixel to give each brick a border
            pNext->block.left = bricksLeft + 1;
            pNext->block.top = bricksTop + 1;

            // subtract 2 from width/height to make room for the 1-pixel
            // border on each side
            pNext->block.width = BRICK_WIDTH - 2;
            pNext->block.height = BRICK_HEIGHT - 2;


            // set row specific properties
            if (row < 2) {
                pNext->block.color = sf::Color::Yellow;
                pNext->points = 1;
                pNext->speedAdjust = 0;
            }
            else if (row < 4) {
                pNext->block.color = sf::Color::Green;
                pNext->points = 3;
                pNext->speedAdjust = 0;
            }
            else if (row < 6) {
                pNext->block.color = sf::Color(255,165,0); // Orange
                pNext->points = 5;
                pNext->speedAdjust = 1;
            }
            else {
                pNext->block.color = sf::Color::Red;
                pNext->points = 7;
                pNext->speedAdjust = 2;
            }

            // set the drawing rectangle
            pNext->block.rectangle.setSize(sf::Vector2f(pNext->block.width, pNext->block.height));
            pNext->block.rectangle.setFillColor(pNext->block.color);
            pNext->block.rectangle.setPosition(pNext->block.left, pNext->block.top);

            // initialize hit flag off so brick is displayed
            pNext->hit = false;

            pNext++;    // get next brick

            bricksLeft += BRICK_WIDTH;
        } // brick columns

        bricksTop -= BRICK_HEIGHT;
    } // brick rows

} // end setup


/**
 * convert user keyboard input into recognized integer values
 * for left=1/up=2/right=3/down=4
 * @return int - user input (default no-input=0, quit=-1)
 */
Direction processInput() {
    Direction input = None;  // no input

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        input = Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        input = Up;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        input = Right;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        input = Down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        input = Exit;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        input = Start;
    }

    return input;
} // end getUserInput


/**
 * update the state of game objects
 * @param input - user keyboard input
 * @param started - has user started the game
 * @param ball  - update ball position and speed
 * @param paddle - player paddle
 * @param bricks - the rack of bricks
 * @param delta - current frame time
 * @returns bool - true if game-over ball hit the bottom wall
 */
bool update(Direction &input, bool &started,
            Ball &ball, MovingBlock &paddle,
            Brick bricks[BRICK_ROWS][BRICK_COLUMNS],
            Borders walls, float delta) {
    bool gameOver = false;

    // adjust velocity directions for user input
    if (input) {
        switch (input) {
            case Left:
                paddle.velocityX -= PADDLE_SPEED;
                break;
            case Right:
                paddle.velocityX += PADDLE_SPEED;
                break;
            case Start:
                if (!started) {
                    ball.velocityX = BALL_SPEED_X;
                    ball.velocityY = BALL_SPEED_Y * -1;
                    /* randomly set horizontal velocity to positive or negative
                       by seeing if the tenths place of current delta
                       (i.e. 1st digit after the decimal) is odd or even.  */
                    if ((int(delta * 10) & 1) % 2) {
                        ball.velocityX *= -1;  // ball goes left if odd
                    }
                    started = true;
                }
        }
        // clear input
        input = None;
    }

    // adjust the location of the ball for speed * time
    paddle.block.left += paddle.velocityX * delta;

    if (started) {
        // adjust the location of the ball for speed * time
        ball.coordinateX += ball.velocityX * delta;
        ball.coordinateY += ball.velocityY * delta;
    }
    else { // not started yet
        // adjust location of ball relative to the paddle
        ball.coordinateX = paddle.block.left + paddle.block.width / 2.0;
        ball.coordinateY = paddle.block.top - ball.radius - 1;
    }

    gameOver = doCollisionChecks(ball, paddle, bricks, walls);

    return gameOver;
} // end update


/**
 * draw the ball on the graphics window
 * @param window - handle to open graphics window
 * @param ball   - structure variable with properties for the ball
 * @param paddle - player paddle
 * @param delta  - amount of frame time plus lag (in ms)
 */
void render(sf::RenderWindow &window, Ball ball, MovingBlock paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders walls, float delta) {
    // Render drawing objects
    // ------------------------------------------------
    // clear the window with the background color
    window.clear(WINDOW_COLOR);

    // --- draw the ball ---
    sf::CircleShape circle;
    circle.setFillColor(ball.color);
    circle.setRadius(ball.radius);
    // set screen coordinates relative to the center of the circle
    circle.setOrigin(ball.radius, ball.radius);
    // calculate current drawing location relative to speed and frame-time
    ball.coordinateX += ball.velocityX * delta;
    ball.coordinateY += ball.velocityY * delta;
    circle.setPosition(ball.coordinateX, ball.coordinateY);
    window.draw(circle);

    // -- draw the player paddle ---
    paddle.block.left += paddle.velocityX * delta;
    paddle.block.top += paddle.velocityY * delta;
    paddle.block.rectangle.setPosition(paddle.block.left, paddle.block.top);
    window.draw(paddle.block.rectangle);

    Brick *pBrick = &bricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int column = 0; column < BRICK_COLUMNS; column++) {
            if (!pBrick->hit) {
                window.draw(pBrick->block.rectangle);
            }
            pBrick++;
        } // columns
    } // rows

    // --- draw the walls ---
    window.draw(walls.leftWall.rectangle);
    window.draw(walls.topWall.rectangle);
    window.draw(walls.rightWall.rectangle);
    window.draw(walls.bottomWall.rectangle);

    // show the new window
    // ------------------------------------------------
    window.display();
} // end render



/**
 * check for collision between game objects
 * @param ball   - the moving ball
 * @param paddle - the player's paddle
 * @param bricks - the rack of bricks
 * @param walls  - border walls
 * @return bool  - true if the ball hit the bottom wall (gameover)
 */
bool doCollisionChecks(Ball &ball, MovingBlock& paddle, Brick bricks[BRICK_ROWS][BRICK_COLUMNS], Borders walls) {
    bool gameOver = false;

    // --- check vertical collisions ---
    if (!collisionCheck(&ball, &paddle.block)) {
        if (!collisionCheck(&ball, &walls.topWall)) {
            gameOver = collisionCheck(&ball, &walls.bottomWall);
        }
    }

    // --- check horizontal collisions ---
    if (!collisionCheck(&ball, &walls.leftWall)) {
        collisionCheck(&ball, &walls.rightWall);
    }

    if (checkBlockCollision(paddle.block, walls.leftWall)) {
        paddle.velocityX = 0.0;
        paddle.block.left = walls.leftWall.left + walls.leftWall.width + 1.0;
    }
    else if (checkBlockCollision(paddle.block, walls.rightWall)) {
        paddle.velocityX = 0.0;
        paddle.block.left = walls.rightWall.left - paddle.block.width - 1.0;
    }

    Brick *pBrick = &bricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int column = 0; column < BRICK_COLUMNS; column++) {
            if (!pBrick->hit) {
                pBrick->hit = collisionCheck(&ball, &pBrick->block);
            }
            pBrick++;
        } // columns
    } // rows

    return gameOver;
} // doCollisionChecks

bool collisionCheck(Ball* pBall, Block* pBlock) {
    bool collision = false;

    int collided = getCollisionPoint(pBall, pBlock);

    if (collided) {
        collision = true;

        // horizontal collisions - invert X coordinate
        // --------------------------------------
        // -- collision left ---
        if (collided > 225 && collided < 315) {
            pBall->velocityX *= -1;
            // collided left, move it right
            pBall->coordinateX = pBlock->left + pBlock->width + pBall->radius + 1;
        }
            // -- collision right ---
        else if (collided > 45 && collided < 135) {
            pBall->velocityX *= -1;
            // collided right, move it left
            pBall->coordinateX = pBlock->left - pBall->radius - 1;
        }

        // vertical collisions - invert Y coordinate
        // --------------------------------------
        // -- collision top ---
        if (collided >= 315 || collided <= 45) {
            pBall->velocityY *= -1;
            // collided top, move it down
            pBall->coordinateY = pBlock->top + pBlock->height + pBall->radius + 1;
        }
            // -- collision bottom ---
        else if (collided >= 135 && collided <= 225) {
            pBall->velocityY *= -1;
            // collided bottom, move it up
            pBall->coordinateY = pBlock->top - pBall->radius - 1;
        }

    } // distance less than radius

    return collision;
} // end collisionCheck


/**
 * calculate the cardinal point on outside of the ball's
 * circumstance that the collision with the block occured
 * and a block
 * @param pBall - center origin of the ball and radius
 * @param pBlock - (x,y) location of block with width and height
 * @return - int cardinal point on outside of circle arc that collision occured
 */
int getCollisionPoint(Ball* pBall, Block* pBlock) {
    int point = 0;

    float checkX, checkY;

    // --- pBall left ---
    if (pBall->coordinateX < pBlock->left)
        checkX = pBlock->left;
        // --- pBall right ---
    else if (pBall->coordinateX > pBlock->left + pBlock->width)
        checkX = pBlock->left + pBlock->width;
        // --- pBall between ---
    else
        checkX = pBall->coordinateX;

    // --- pBall above ---
    if (pBall->coordinateY < pBlock->top) // inverted Y
        checkY = pBlock->top;
        // --- pBall below ---
    else if (pBall->coordinateY > pBlock->top + pBlock->height) // inverted Y
        checkY = pBlock->top + pBlock->height;
        // --- pBall between ---
    else
        checkY = pBall->coordinateY;

    // find difference between check (x,y) and pBall (x,y)
    double diffX = checkX - pBall->coordinateX;
    double diffY = (WINDOW_HEIGHT - checkY) - (WINDOW_HEIGHT - pBall->coordinateY);

    // calculate linear distance using Pythagorean Theorem
    double distance = std::sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));

    if (distance <= pBall->radius) {

        // calculate the arc-tangent of the slope
        double theta = std::atan2(diffY, diffX);

        // convert this to cardinal degrees
        double degrees = 90.0 - theta * 180.0 / M_PI;
        if (degrees <= 0)
            degrees += 360;

        point = int(degrees);
    }

    return point;
} // end getCollisionPoint


bool checkBlockCollision(Block moving, Block stationary) {
    bool collision = false;

    if (moving.left < stationary.left + stationary.width &&
        moving.left + moving.width > stationary.left &&
        moving.top < stationary.top + stationary.height &&
        moving.top + moving.height > stationary.top) {
        collision = true;
    }

    return collision;
}