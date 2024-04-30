/**
 * @file WelcomeScreen.h
 * @author Yolexis Rodriguez
 * @brief Class that implement the function prototypes in  welcome screen 
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */
#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "button.h"

#include <iostream>

class WelcomeScreen
{
public:
    WelcomeScreen(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void updateButtons();
    int handleInput(sf::Event &event, sf::RenderWindow& window);



private:
    //sf::RenderWindow& mWindow;
    sf::Texture texture;
    sf::Sprite snake;
    sf::Texture background1;
    sf::Sprite background;
    sf::Texture header1;
    sf::Sprite header;
    Button button1;
    Button button2;
    Button button3;

};

#endif