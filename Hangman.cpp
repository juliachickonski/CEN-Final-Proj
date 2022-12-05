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
sf::Event event;

//global variables
int len; //length of word
int wordCounter = 0;
int livesCounter = 0; //tracks users lives
int lastCount = 0;

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

void render(sf::RenderWindow &window, int userLives , const string& gWord, char userInput,int length, char userArray[], bool win){
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
    gameWord.setString(gWord);
    gameWord.setFont(textFont);
    gameWord.setCharacterSize(40);
    gameWord.setStyle(sf::Text::Bold);
    gameWord.setPosition(12,800);

    sf::Text lengthText; // tells user how many letters the word they are trying to guess is
    lengthText.setString("Number of letters in word: " );
    lengthText.setFont(textFont);
    lengthText.setCharacterSize(30);
    lengthText.setStyle(sf::Text::Bold);
    lengthText.setPosition(12,12);

    sf::Text wordLength;
    wordLength.setString(std::to_string(length));
    wordLength.setFont(textFont);
    wordLength.setCharacterSize(30);
    wordLength.setStyle(sf::Text::Bold);
    wordLength.setPosition(400,12);

    sf::RectangleShape wordLine(sf::Vector2f(150, 5));
    
    if (win){
        userLives = 0;
    }

    switch(userLives){
        case 7:
            window.clear();
            window.draw(gameWord);

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(wordLength);
            window.draw(lengthText);

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

            window.draw(winText);

            window.draw(wordLength);
            window.draw(lengthText);

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

//checks if letter guessed 
char guessCheck(const char wordArray[], char userChoice, char userArray[], const string& word) {
    for (int i = 0; i < word.length(); i++) {
        if (userChoice == wordArray[i]) {
            userArray[i] = userChoice;
            livesCounter++;
            wordCounter++;
        }
    }
    return userArray[len];
}

void gameTime(const string& word,sf::RenderWindow &window){
    len = word.length(); //length of word to be guessed

    int userLife = 7; //number of lives the user has to guess the word default 7
    char userInput = {}; //the letter the user guesses
    char wordArray[len]; //array to hold the word to guess
    char userArray[len]; //array to hold users correct guesses
    bool win = false;
    bool gameOver = false;
    bool wait = false;

    for (int i = 0; i < len; i++) {
        userArray[i] = ' ';
    }

    strcpy(wordArray, word.c_str()); //copies the word letter by letter into wordArray

    render(window,userLife, word, userInput, len, userArray, win);

     while (window.isOpen())
    {
         while (window.pollEvent(event))
         {
             while (!gameOver)
             {
                 window.setKeyRepeatEnabled(false);
                 switch (event.type)
                 {
                     case sf::Event::KeyPressed:
                         if (!wait) {
                             switch (event.key.code) {
                                 case sf::Keyboard::A:
                                     userInput = 'a';
                                     cout << userInput;
                                     guessCheck(&wordArray[len], userInput, userArray, word);
                                     render(window, userLife, word, userInput, len, userArray, win);
                                     break;

                                     case sf::Keyboard::B:
                                      userInput = 'b';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::C:
                                        userInput = 'c';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::D:
                                        userInput = 'd';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::E:
                                        userInput = 'e';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::F:
                                        userInput = 'f';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::G:
                                        userInput = 'g';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::H:
                                        userInput = 'h';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::I:
                                        userInput = 'i';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::J:
                                        userInput = 'j';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::K:
                                        userInput = 'k';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::L:
                                        userInput = 'l';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::M:
                                        userInput = 'm';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::N:
                                        userInput = 'n';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::O:
                                        userInput = 'o';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::P:
                                        userInput = 'p';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::Q:
                                        userInput = 'q';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::R:
                                        userInput = 'r';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::S:
                                        userInput = 's';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::T:
                                        userInput = 't';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::U:
                                        userInput = 'u';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::V:
                                        userInput = 'v';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::W:
                                        userInput = 'w';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::X:
                                        userInput = 'x';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                    case sf::Keyboard::Y:
                                        userInput = 'y';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;

                                    case sf::Keyboard::Z:
                                        userInput = 'z';
                                        guessCheck(&wordArray[len], userInput, userArray, word);
                                        render(window, userLife, word, userInput, len, userArray, win);
                                        break;
                                }
                            }
                            break;
                }
               if (livesCounter == lastCount) {
                   userLife--;
               }
               if (wordCounter == len) {
                   win = true;
               }
               render(window,userLife, word, userInput, len, userArray, win);
            }
        }

    }
}

//game difficulty choice
void hangman(sf::RenderWindow &window) {
    HangmanMenu HangmanMenu(window.getSize().x, window.getSize().y);

    string word;
    while (window.isOpen()) {
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