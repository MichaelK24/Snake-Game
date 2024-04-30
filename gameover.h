/**
 * @file gameover.h
 * @author Michael King
 * @brief 
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "welcomeScreen.h"
#include "button.h"

class gameover
{
public:
    gameover(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    int handleInput(sf::Event &event, sf::RenderWindow& window);
    void updateButtons();

private:
    Button backButton;
    sf::Texture texture;
    sf::Sprite gameoverscreen;
    sf::Text text;


};

#endif