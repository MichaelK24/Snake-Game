#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "snake.h"
#include "board.h"
#include <iostream>
#include <unistd.h>

class GameScreen
{
public:
    GameScreen(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void update();
    int handleInput(sf::Event &event);
    void reset();

private:
    Board mBoard;
    sf::Sprite mBackground;
    Snake mSnake;
    sf::Clock move;
    sf::Time move2;
   // sf::Texture mTexture;
    bool gameOver;
    int score;
};

#endif

