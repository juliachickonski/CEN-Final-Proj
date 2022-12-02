//
// Created by julia on 12/1/2022.
//

#ifndef COP_FINAL_HANGMANMENU_H
#define COP_FINAL_HANGMANMENU_H

#pragma once
#include <SFML/Graphics.hpp>

#define MAX_MENU_ITEMS 4

class HangmanMenu{
public:
    HangmanMenu(float width, float height);
    ~HangmanMenu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_MENU_ITEMS];

};

#endif //COP_FINAL_HANGMANMENU_H
