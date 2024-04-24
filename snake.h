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
#include <ncurses.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "board.h"

class Snake
{
private:
    //void update();
    int score = 0;
    std::string lastMove;
    Board myBoard;
    //char board[17][17];
    // int direction;
    // void pointGain(char apple, char snakeHead, int score);
    // void directionInput();
public:
    struct Point{
        int x;
        int y;
    };
    Snake(Board myBoard);
    void eatApple();
    void turnInput();
    void actualTurn();
    void start();
    void drawSnake();

    // void Colition();
    //char snakeHead = 's';
    //char snakeBody = 'b';
    // char apple = 'A'; 
    std::string directions[5]={"up", "down", "left", "right", "end"};
    std::vector<Point> snake;
    bool gameOver;
    std::string dir;

};

#endif