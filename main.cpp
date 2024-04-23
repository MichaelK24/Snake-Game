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
#include "board.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include "welcomeScreen.h"
#include "game.h"



// int main()
// {

//     sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");

//     Screen startScreen(window);
//     Button button3("START", {300, 700}, {375, 100}, sf::Color::Red);
//     Button button2("RULES", {700, 700}, {375, 100}, sf::Color::Red);
//     Button button1("EXIT", {1100, 700}, {375, 100}, sf::Color::Red);



//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {   
//             if (event.type == sf::Event::Closed)
//             window.close();

//             button1.update(event, window);
//             button2.update(event, window);
//             button3.update(event, window);
//         }

//         window.clear();
//         startScreen.draw();
//         window.draw(button1);
//         window.draw(button2);
//         window.draw(button3);
//         window.display();
//     }

//     return 0;
// }

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
            game.update(event);
        }

        game.render();
    }

    return 0;
}
