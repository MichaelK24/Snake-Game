/**
 * @file main.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */
#include "snake.h"
#include "board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include "welcomeScreen.h"
#include "game.h"


int main()
{
    Game game;

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (!game.isDone())
    {
        timeSinceLastUpdate += clock.restart();
        sf::Event event;
        game.handleInput(event);

        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            //game.handleInput(event);
            game.update();
        }

        game.render();
    }
    
    return 0;
}
