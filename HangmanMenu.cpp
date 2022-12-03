#include "HangmanMenu.h"
using namespace std;
//sf::Font font;
HangmanMenu::HangmanMenu(float width, float height) {
    //handle filetype structures for mac & windows
    if(!font.loadFromFile("../arial.ttf")) //windows
    {
        if(!font.loadFromFile("arial.ttf")) //mac
        {

        }
    }
    //first menu item
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Easy");
    menu[0].setPosition(sf::Vector2f(width /2,  height / (MAXIMUM_MENU_ITEMS + 1) * 1 ));

    //second menu item
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Medium: One hint");
    menu[1].setPosition(sf::Vector2f(width /2,  height / (MAXIMUM_MENU_ITEMS + 1) * 2 ));

    //third menu item
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Hard--No Hints");
    menu[2].setPosition(sf::Vector2f(width /2,  height / (MAXIMUM_MENU_ITEMS + 1) * 3 ));

    //quit Hangman menu option
    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Back");
    menu[3].setPosition(sf::Vector2f(width /2,  height / (MAXIMUM_MENU_ITEMS + 1) * 4 ));

    selectedItemIndex = 0;
}

HangmanMenu::~HangmanMenu() = default;

void HangmanMenu::draw(sf::RenderWindow &window) {
    for (int i=0; i<MAXIMUM_MENU_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void HangmanMenu::moveUp()
{
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void HangmanMenu::moveDown()
{
    if (selectedItemIndex + 1 < MAXIMUM_MENU_ITEMS) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}




