/**
 * @file snake.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
//#include <ncurses.h>
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>


const float TileWidth = 55; //sqrt(sf::VideoMode::getDesktopMode().width * sf ::VideoMode::getDesktopMode().height)/(17*17);
//sf::RectangleShape player(sf::Vector2f(TileWidth,TileWidth));
//tile width is equal to the square root of the length and width of the window, all divided by 17 squared
const sf::Vector2f TOP = {500, 10};

class Snake
{
private:
    struct Point{
        int x;
        int y;
    };
    //void update();
    int score = 0;
    std::string lastMove;
    char board[17][17];
    std::string directions[5]={"up", "down", "left", "right", "end"};
    std::vector<Point> snake;
    sf::RectangleShape array[17][17];
    bool gameOver;
    std::string dir;
    void initBoard();
    // int direction;
    // void pointGain(char apple, char snakeHead, int score);
    // void directionInput();
public:
    
    Snake(sf::RenderWindow& window);
    void eatApple();
    void turnInput(sf::Event &evnt);
    void start();
    void draw(sf::RenderWindow& window);
    bool actualTurn();
    void update();

    // void Colition();
    //char snakeHead = 's';
    //char snakeBody = 'b';
    // char apple = 'A'; 
    

};

#endif