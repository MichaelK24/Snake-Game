#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "snake.h"
#include "board.h"
#include <iostream>

class GameScreen
{
public:
    GameScreen(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void update();
    int handleInput(sf::Event &event);

private:
    Board mBoard;
    sf::Sprite mBackground;
    Snake mSnake;
    sf::Texture mTexture;
    bool gameOver;

};

#endif

