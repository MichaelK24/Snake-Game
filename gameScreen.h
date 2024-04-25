#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "snake.h"
#include <iostream>

class GameScreen
{
public:
    GameScreen(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void update();
    void handleInput(sf::Event &event);

private:
    //Board mBoard;
    Snake mSnake;

};

#endif

