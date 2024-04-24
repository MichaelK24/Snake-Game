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
    void updateButtons(sf::Event &event, sf::RenderWindow& window);

private:
    //sf::RenderWindow& mWindow;
    sf::Texture texture;
    sf::Sprite snake;
    sf::Texture background1;
    sf::Sprite background;
    sf::Texture header1;
    sf::Sprite header;
    Button button3;
    Button button2;
    Button button1;
};

#endif




// #ifndef SCREEN_H
// #define SCREEN_H
// #include <iostream>
// #include <SFML/Graphics.hpp>
// using namespace sf;

// class Screen
// {
// public:
//     Screen(sf::RenderWindow &window);
//     void draw();


// private:
//     sf::RenderWindow &gameWindow;
//     sf::Texture texture;
//     sf::Texture background1;
//     sf::Sprite snake;
//     sf::Sprite background;
//     sf::Texture header1;
//     sf::Sprite header;



// };
  
// #endif