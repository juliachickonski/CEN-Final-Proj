#include "Menu.h"

using namespace std;
sf::Font font;
Menu::Menu(float width, float height) {
    //handle filetype structures for mac & windows
    if(!font.loadFromFile("../arial.ttf")) //windows
    {
        if(!font.loadFromFile("arial.ttf")) //mac
        {

        }
    }
    //first menu item
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play Breakout");
    menu[0].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 1 ));

    //second menu item
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Play Hangman");
    menu[1].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 2 ));

    //third menu item
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 3 ));

    selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for (int i=0; i<MAX_MENU_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

//moves menu indicator up
void Menu::moveUp()
{
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex + 1 < MAX_MENU_ITEMS) {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
