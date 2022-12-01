#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Hangman.h"
#include "breakout_defs.h"
#include<iostream>
using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML WORKING");

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
                                    hangman(window);
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
