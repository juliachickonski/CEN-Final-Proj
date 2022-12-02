#include "Hangman.h"
#include "HangmanMenu.h"
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

void game(string word) {
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
/*
void menu(sf::RenderWindow &window) {
    window.clear(BACKGROUND_COLOR);
    window.display();
}*/

//Main game
void hangman(sf::RenderWindow &window) {
    window.clear();
    HangmanMenu HangmanMenu(window.getSize().x, window.getSize().y);
    HangmanMenu.draw(window);
    window.display();

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
                                    game(word);
                                case 1:
                                    word = medium();
                                    game(word);
                                    break;
                                case 2:
                                    word = hard();
                                    game(word);
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
    }
}
//}