#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Screen
{
public:
    Screen(sf::RenderWindow &window);
    void draw();

private:
    sf::RenderWindow &gameWindow;
    sf::Texture texture;
    sf::Texture background1;
    sf::Sprite snake;
    sf::Sprite background;
    sf::Texture header1;
    sf::Sprite header;

};
  
#endif