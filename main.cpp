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
// #include "button.h"
#include "screen.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    Screen startScreen(window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        //window.draw(shape);
        startScreen.draw();
        window.display();
    }

    return 0;
}
//     sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing sprite.");
//     while (window.isOpen())
//    {
//        sf::Event event;

//        startScreen(window);


    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //        yes.update(event, window);
    //       no.update(event, window);
    //    }

    //     window.clear();
    //     window.draw(yes);
    //     window.draw(no);
    //     window.display();
   

