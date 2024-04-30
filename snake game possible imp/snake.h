#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <SFML/Graphics.hpp>

class snake {
public:
    snake(sf::RenderWindow& window);
    void run();

private:
    void setup();
    void processInput();
    void update();
    void render();

    sf::RenderWindow& window;
    const int width = 17;
    const int height = 17;
    int snakeX[196], snakeY[196];
    int fruitX, fruitY;
    int snakeLength;
    bool gameOver;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;
};

#endif