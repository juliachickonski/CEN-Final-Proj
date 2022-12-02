/* --------------------------------------------------------
 *    File: breakout_defs.h
 *  Author: Tyler MacPhee
 *   Class: CEN 3031, Fall 2022
 * Purpose: Stores constants & structs for the breakout game
 * -------------------------------------------------------- */
#include <SFML/Graphics.hpp>

#ifndef BREAKOUTPADDLE_BREAKOUT_DEFS_H
#define BREAKOUTPADDLE_BREAKOUT_DEFS_H
// Global Constants
// --------------------------------------------------------

// window properties
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const sf::Color WINDOW_COLOR = sf::Color::Black;

// drawing properties
const float FRAME_RATE = (1.0/30.0) * 1000.0;       // FPS in ms
const sf::Color BALL_COLOR = sf::Color::Blue;
const float WALL_THICKNESS = 2.0;
const sf::Color WALL_COLOR = sf::Color::Green;

// ball properties
const float BALL_RADIUS = 20.0;
const float BALL_SPEED_X = BALL_RADIUS * 10.0 / 1000.0;
const float BALL_SPEED_Y = BALL_RADIUS * 8.5 / 1000.0;

// paddle constants
const float PADDLE_WIDTH = 160.0;
const float PADDLE_THICKNESS = 10.0;
const sf::Color PADDLE_COLOR = sf::Color::Magenta;
const float PADDLE_SPEED = PADDLE_WIDTH / 10.0 / 1000.0;

// --- brick constants ---
const int BRICK_ROWS = 8;                                               // rows of bricks in rack
const int BRICK_COLUMNS = 14;                                           // number of bricks in row
const float BRICK_WIDTH = WINDOW_WIDTH / BRICK_COLUMNS;                 // width of 1 brick
const float BRICK_HEIGHT = PADDLE_THICKNESS * 2;                        // height of 1 brick (2 x paddle)
const float BRICKS_HEIGHT = BRICK_ROWS * BRICK_HEIGHT;                  // height of rack of bricks
const float BRICKS_TOP = WINDOW_HEIGHT / 2.0 - BRICKS_HEIGHT * 0.75;    // top of the rack (shift up 3/4 from center)
const float BRICKS_LEFT = WALL_THICKNESS;                               // left of first brick in each row
const float FIRST_BRICK = BRICKS_TOP + (BRICK_ROWS - 1) * BRICK_HEIGHT; // top of lowest brick in rack


// Type definitions
// --------------------------------------------------------
enum Direction {
    Exit = -1,
    None,
    Left,
    Up,
    Right,
    Down,
    Start
};

struct Ball {
    float radius;
    float coordinateX;
    float coordinateY;
    float velocityX;
    float velocityY;
    sf::Color color;
};

struct Block {
    float left;
    float top;
    float width;
    float height;
    sf::Color color;
    sf::RectangleShape rectangle;
};

struct MovingBlock {
    Block block;
    float velocityX;
    float velocityY;
};

struct Brick {
    Block block;
    bool hit;
    int points;
    float speedAdjust;
};

struct Borders {
    Block leftWall;
    Block topWall;
    Block rightWall;
    Block bottomWall;
};

void breakout(sf::RenderWindow &window);

#endif //BREAKOUTPADDLE_BREAKOUT_DEFS_H
