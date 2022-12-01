#include <SFML/Graphics.hpp>
#include "menu.h"
#include "hangman.h"
#include "breakout_defs.h"
#include<iostream>
using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORKING");

    Menu menu(window.getSize().x, window.getSize().y);

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
                            menu.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.getPressedItem())
                            {
                                case 0:
                                    breakout(window);
                                    break;
                                case 1:
                                    hangman();
                                    break;
                                case 2:
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

        menu.draw(window);

        window.display();
    }
    //change

    return 0;
}
