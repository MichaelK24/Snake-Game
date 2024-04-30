#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>

const float TileWidth = 55;
const sf::Vector2f TOP = {500, 10};

class Snake {
private:
    struct Point {
        int x;
        int y;
    };

    int score;
    std::string dir;
    char board[17][17];
    std::vector<Point> snake;
    sf::RectangleShape array[17][17];
    bool gameOver;
    
    void initBoard();

public:
    Snake(sf::RenderWindow& window);
    void turnInput(sf::Event& event);
    bool actualTurn();
    void draw(sf::RenderWindow& window);
    bool isGameOver();
    int getScore();
    void reset();
    void update();
};

#endif