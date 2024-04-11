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
#include "screen.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");

    Screen startScreen(window);
    Button button1("Button 1", {1000, 700}, {500, 400}, sf::Color::Green);
    Button button2("Button 2", {1000, 500}, {500, 400},sf::Color::Green);
    Button button3("Button 3", {1000, 300}, {500, 400}, sf::Color::Green);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            window.close();

            button1.update(event, window);
            button2.update(event, window);
            button3.update(event, window);
        }

        window.clear();
        startScreen.draw();
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.display();
    }

    return 0;
}

   

