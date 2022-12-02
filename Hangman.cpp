#include "Hangman.h"
#include "HangmanMenu.h"
//#include "main.cpp"
//#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;

sf::Font textfont;

void returnArray(string arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



string easy() {
    // hint animals
    // maybe one letter already revealed
    string word[5] = {"bear", "hippo", "rabbit", "monkey", "horse"};

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
    string word[5] = {"bowzer", "glados", "gannon", "ridley", "robotnik"};

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
    string word[5] = {"jazz", "abrupt", "match", "rythm", "buzzing"};

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

void game(string word,sf::RenderWindow &window) {
    if(!textfont.loadFromFile("../arial.ttf")) //windows
    {
        if(!textfont.loadFromFile("arial.ttf")) //mac
        {

        }
    }

    //word bank shapes
    sf::RectangleShape wordBank(sf::Vector2f(300,600));
    wordBank.setFillColor(sf::Color(0, 0, 0));
    wordBank.setOutlineThickness(25);
    wordBank.setOutlineColor(sf::Color(255, 255, 255));
    wordBank.setPosition(1500, 225);

    sf::Text bankText;
    bankText.setString("Letter Graveyard");
    bankText.setFont(textfont);
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
    sf::CircleShape head(50);
    head.setPointCount(100);
    head.setPosition(683,240);
    sf::RectangleShape torso(sf::Vector2f(125,5));
    torso.rotate(90);
    torso.setPosition(735,340);
    sf::RectangleShape lLeg(sf::Vector2f(75,5));
    lLeg.rotate(135);
    lLeg.setPosition(735,465);
    sf::RectangleShape rLeg(sf::Vector2f(75,5));
    rLeg.rotate(45);
    rLeg.setPosition(736,464);

    sf::RectangleShape lArm(sf::Vector2f(75,5));
    lArm.rotate(-135);
    lArm.setPosition(730,391);
    sf::RectangleShape rArm(sf::Vector2f(75,5));
    rArm.rotate(-45);
    rArm.setPosition(732,388);

    window.clear();
    window.draw(head);
    window.draw(torso);
    window.draw(lLeg);
    window.draw(rLeg);
    window.draw(lArm);
    window.draw(rArm);

    //window.clear();
    window.draw(wordBank);
    window.draw(bankText);
    window.draw(baseLine);
    window.draw(standLine);
    window.draw(hookLine);
    window.draw(hookLine2);
    window.display();

    int len = word.length();
    char wordArray[len];
    strcpy(wordArray, word.c_str());
    char userArray[len];

    for (int i = 0; i < len; i++) {
        userArray[i] = '_';
    }

    int userLife = 9; // user life count before stick figure
    char userChoice;
    for (int i = 0; i < len; i++) {
        cout << " ___ ";
    }
    int wordCounter = 0;
    int livesCounter = 0;
    int lastCount = 0;
    cout << "number of lives: " << userLife << endl;
    while (userLife > 0) {
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
            break;
        }
        if (livesCounter == lastCount) {
            userLife--;
        }
        lastCount = livesCounter;
        cout << "number of lives: " << userLife << endl;
        if (userLife == 0) {
            cout << "You Loose :(\n\n";
            return;
        }
    }
}

//Main game
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
                                    cout << word;
                                    game(word,window);
                                case 1:
                                    word = medium();
                                    cout << word;
                                    game(word,window);
                                    break;
                                case 2:
                                    word = hard();
                                    cout << word;
                                    game(word,window);
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