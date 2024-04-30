/**
 * @file WRules.h
 * @author Yolexis Rodriguez
 * @brief Class that create function prototype of the rules screen
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */

#ifndef RULES_H
#define RULES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "welcomeScreen.h"
#include "button.h"

class Rules
{
public:
    Rules(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    // void handleInput(sf::Event &event, sf::RenderWindow& window);
    int handleInput(sf::Event &event, sf::RenderWindow& window);
    void updateButtons();

private:
    Button backButton;
    sf::Texture texture;
    sf::Texture rulesBackground1;
    sf::Sprite rulesBackground2;
    sf::Text text;
    //sf::RenderTexture textTexture;
    sf::Font font; // Declare font her

};

#endif