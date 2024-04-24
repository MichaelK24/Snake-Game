#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "game.h"

class GameScreen
{
public:
    GameScreen(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void update(sf::Event &event, sf::RenderWindow& window);

private:
    Board mBoard;
    Snake mSnake;

};

#endif
