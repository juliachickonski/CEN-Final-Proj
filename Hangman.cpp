#include "Hangman.h"
#include "HangmanMenu.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;

sf::Font textFont;

void render(sf::RenderWindow &window, int userLives , string gWord, char userInput){
    if(!textFont.loadFromFile("../arial.ttf")) //windows
    {
        if(!textFont.loadFromFile("arial.ttf")) //mac
        {
        }
    }
    //word bank shapes
    //word bank box
    sf::RectangleShape wordBank(sf::Vector2f(300,600));
    wordBank.setFillColor(sf::Color(0, 0, 0));
    wordBank.setOutlineThickness(25);
    wordBank.setOutlineColor(sf::Color(255, 255, 255));
    wordBank.setPosition(1500, 225);

    //word bank title
    sf::Text bankText;
    bankText.setString("Letter Graveyard");
    bankText.setFont(textFont);
    bankText.setCharacterSize(40);
    bankText.setStyle(sf::Text::Bold);
    bankText.setPosition(1493,155);

    sf::Text letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i].setPosition(3010,610);
        letters[i].setFont(textFont);
        letters[i].setFillColor((sf::Color(255, 255, 255)));
        letters[i].setCharacterSize(40);
    }
    letters[0].setString('a');
    letters[1].setString('b');
    letters[2].setString('c');
    letters[3].setString('d');
    letters[4].setString('e');
    letters[5].setString('f');
    letters[6].setString('g');
    letters[7].setString('h');
    letters[8].setString('i');
    letters[9].setString('j');
    letters[10].setString('k');
    letters[11].setString('l');
    letters[12].setString('m');
    letters[13].setString('n');
    letters[14].setString('o');
    letters[15].setString('p');
    letters[16].setString('q');
    letters[17].setString('r');
    letters[18].setString('s');
    letters[19].setString('t');
    letters[20].setString('u');
    letters[21].setString('v');
    letters[22].setString('w');
    letters[23].setString('x');
    letters[24].setString('y');
    letters[25].setString('z');


    //hangman holder shape
    sf::RectangleShape baseLine(sf::Vector2f(300,5));
    baseLine.setPosition(735,590);
    sf::RectangleShape standLine(sf::Vector2f(400,5));
    standLine.rotate(90);
    standLine.setPosition(885,190);
    sf::RectangleShape hookLine(sf::Vector2f(150,5));
    hookLine.setPosition(735,190);
    sf::RectangleShape hookLine2(sf::Vector2f(50,5));
    hookLine2.rotate(90);
    hookLine2.setPosition(735,190);

    //draw human
    //head
    sf::CircleShape head(50);
    head.setPointCount(100);
    head.setPosition(683,240);
    //torso
    sf::RectangleShape torso(sf::Vector2f(125,5));
    torso.rotate(90);
    torso.setPosition(735,340);
    //left leg
    sf::RectangleShape lLeg(sf::Vector2f(75,5));
    lLeg.rotate(135);
    lLeg.setPosition(735,465);
    //right leg
    sf::RectangleShape rLeg(sf::Vector2f(75,5));
    rLeg.rotate(45);
    rLeg.setPosition(736,464);
    //left arm
    sf::RectangleShape lArm(sf::Vector2f(75,5));
    lArm.rotate(-135);
    lArm.setPosition(730,391);
    //right arm
    sf::RectangleShape rArm(sf::Vector2f(75,5));
    rArm.rotate(-45);
    rArm.setPosition(732,388);

    sf::Text winText;
    winText.setString("\t\tYou Earned a Point! \nPress enter to continue.");
    winText.setFont(textFont);
    winText.setCharacterSize(50);
    winText.setStyle(sf::Text::Bold);
    winText.setPosition(750,25);

    sf::Text loseText;
    loseText.setString("\t\t\tYou Loose :( \nPress enter to return to Menu.");
    loseText.setFont(textFont);
    loseText.setFillColor(sf::Color(255,66,0));
    loseText.setCharacterSize(50);
    loseText.setStyle(sf::Text::Bold);
    loseText.setPosition(625,25);

    sf::Text gameWord;
    gameWord.setString(userInput);
    gameWord.setFont(textFont);
    gameWord.setCharacterSize(40);
    gameWord.setStyle(sf::Text::Bold);
    gameWord.setPosition(12,12);

    sf::RectangleShape wordLine(sf::Vector2f(150, 5));

    switch(userLives){
        case 7:
            window.clear();
            window.draw(gameWord);

            window.draw(letters[0]);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.display();
            break;

        case 6:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);

            window.display();
            break;

        case 5:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);
            window.draw(torso);

            window.display();
            break;

        case 4:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);
            window.draw(torso);
            window.draw(lLeg);

            window.display();
            break;

        case 3:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);
            window.draw(torso);
            window.draw(lLeg);
            window.draw(rLeg);

            window.display();
            break;

        case 2:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);
            window.draw(torso);
            window.draw(lLeg);
            window.draw(rLeg);
            window.draw(lArm);

            window.display();
            break;

        case 1:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);
            window.draw(torso);
            window.draw(lLeg);
            window.draw(rLeg);
            window.draw(lArm);
            window.draw(rArm);

            window.draw(loseText);

            window.display();
            break;

        case 0:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.draw(head);

            window.display();
            break;

        default:
            window.clear();
            window.draw(gameWord);

            window.draw(wordBank);
            window.draw(bankText);
            window.draw(baseLine);
            window.draw(standLine);
            window.draw(hookLine);
            window.draw(hookLine2);

            window.display();
            break;
    }

}

string easy() {
    // hint animals
    // maybe one letter already revealed
    string word[5] = {"bear", "hippo", "rabbit", "monkey", "horse"}; //4  5  6  6  5

    // found random number generator
    // https://java2blog.com/random-number-between-1-and-10-cpp/
    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
            break;
        case 2:
            return word[1];
            break;
        case 3:
            return word[2];
            break;
        case 4:
            return word[3];
            break;
        case 5:
            return word[4];
            break;
        default:
            cout<< "Sorry, that is not a valid choice.";
            break;
    }
    return word[0];
}

string medium() {
    // hint but no free letter
    // Gamer Villains
    string word[5] = {"bowzer", "glados", "gannon", "ridley", "robotnik"}; //6  6  6  6  8

    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
        case 2:
            return word[1];
        case 3:
            return word[2];
        case 4:
            return word[3];
        case 5:
            return word[4];
        default:
            break;
    }
    return word[0];
}

string hard() {
    // no hints and random words
    string word[5] = {"jazz", "abrupt", "match", "rythm", "buzzing"};// 4  6  5  5  7

    srand(time(0));
    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            return word[0];
        case 2:
            return word[1];
        case 3:
            return word[2];
        case 4:
            return word[3];
        case 5:
            return word[4];
        default:
            break;
    }
    return word[0];
}

int enterLetter(sf::RenderWindow &window) {
    if (!textFont.loadFromFile("../arial.ttf")) //windows
    {
        if (!textFont.loadFromFile("arial.ttf")) //mac
        {

        }
    }

    sf::Event event;
    sf::String playerInput;
    sf::Text playerText;
    playerText.setPosition(60, 300);
    playerText.setColor(sf::Color::Red);
    playerText.setCharacterSize(75);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    if (event.text.unicode > 96 && event.text.unicode < 123) {
                        playerInput += event.text.unicode;
                        playerText.setString(playerInput);
                    }
                    break;
            }
            window.clear();
            window.draw(playerText);
            window.display();
        }
        window.display();
    }
    return 0;
}

void gameTime(string word,sf::RenderWindow &window){
    int userLife = 7; //number of lives the user has to guess the word default 7
    int len = word.length(); //determines length of word to guess
    int wordCounter = 0;
    int livesCounter = 0; //tracks users lives
    int lastCount = 0;
    char userInput = ';'; //the letter the user guesses
    char wordArray[len]; //array to hold the word to guess
    char userArray[len]; //array to hold users correct guesses
    bool gameOver = false;


    strcpy(wordArray, word.c_str()); //copies the word letter by letter into wordArray

    //fills user array with spaces
    for (int i = 0; i < len; i++) {
        userArray[i] = ' ';
    }
    render(window,userLife,word,userInput);
    while (!gameOver) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::A:
                            userInput = 'a';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::B:
                            userInput = 'b';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::C:
                            userInput = 'c';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::D:
                            userInput = 'd';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::E:
                            userInput = 'e';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::F:
                            userInput = 'f';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::G:
                            userInput = 'g';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::H:
                            userInput = 'h';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::I:
                            userInput = 'i';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::J:
                            userInput = 'j';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::K:
                            userInput = 'k';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::L:
                            userInput = 'l';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::M:
                            userInput = 'm';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::N:
                            userInput = 'n';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::O:
                            userInput = 'o';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::P:
                            userInput = 'p';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::Q:
                            userInput = 'q';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::R:
                            userInput = 'r';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::S:
                            userInput = 's';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::T:
                            userInput = 't';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::U:
                            userInput = 'u';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::V:
                            userInput = 'v';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::W:
                            userInput = 'w';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::X:
                            userInput = 'x';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::Y:
                            userInput = 'y';
                            render(window,userLife,word,userInput);
                            break;
                        case sf::Keyboard::Z:
                            userInput = 'z';
                            render(window,userLife,word,userInput);
                            break;
                        }
                    }
            }
        }
    render(window,userLife,word, userInput);
    }
}

void game(string word,sf::RenderWindow &window) {
    int len = word.length(); //determines length of word to guess
    char wordArray[len]; //array to hold the word to guess
    strcpy(wordArray, word.c_str());
    char userArray[len]; //array to hold users guesses

    for (int i = 0; i < len; i++) {
        userArray[i] = '_';
    }

    int userLife = 9; // user life count before stick figure
    char userChoice;

    for (int i = 0; i < len; i++) { //puts out number of lines/letter in console
        cout << " ___ ";
    }

    int wordCounter = 0;
    int livesCounter = 0;
    int lastCount = 0;

    cout << "number of lives: " << userLife << endl;

    while (userLife > 0) {//while the player has more than 0 lives
        //render(window,userLife, );

        cout << "letter choice: ";
        cin >> userChoice;
        cout << endl;
        for (int i = 0; i < word.length(); i++) {
            if (userChoice == wordArray[i]) {
                userArray[i] = userChoice;
                cout << " _" << userArray[i] << "_ ";
                livesCounter++;
                wordCounter++;
            } else {
                cout << " _" << userArray[i] << "_ ";
            }
        }
        for (int i = 0; i < word.length(); i++) {
            if (userArray[i] == wordArray[i]) {
                int num;
            }
        }
        if (wordCounter == len) {
            cout << "Congrats! You win";
            return;
        }
        if (livesCounter == lastCount) {
            userLife--;
        }
        lastCount = livesCounter;
        cout << "number of lives: " << userLife << endl;

        if (userLife == 0) {
            window.clear();
            sf::Text loseTxt;
            loseTxt.setString("YOU LOOSE");
            loseTxt.setFont(textFont);
            loseTxt.setCharacterSize(75);
            loseTxt.setStyle(sf::Text::Bold | sf::Text::Underlined);
            loseTxt.setFillColor(sf::Color(178,34,34));
            loseTxt.setPosition(960,540);
            window.draw(loseTxt);
            window.display();
            cout << "You Loose :(\n\n";
            return;
        }
    }
}

//game difficulty choice
void hangman(sf::RenderWindow &window) {
    HangmanMenu HangmanMenu(window.getSize().x, window.getSize().y);

    string word;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            HangmanMenu.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            HangmanMenu.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (HangmanMenu.getPressedItem())
                            {
                                case 0:
                                    word = easy();
                                    gameTime(word,window);
                                    //game(word,window);
                                case 1:
                                    word = medium();
                                    gameTime(word,window);
                                    break;
                                case 2:
                                    word = hard();
                                    gameTime(word,window);
                                    break;
                                case 3:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();

        HangmanMenu.draw(window);

        window.display();
    }
}