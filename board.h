/**
 * @file board.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#ifndef BOARD_H
#define BOARD_H
static int const size=17;
class Board
{
private:
    static int const size=17;
    int score=0;
public:
    Board();
    void update();
    void placeapple(char array[size][size],int score);
    void setupboard(char array[size][size],int size);
    void displayboard(char array[size][size]);
};


#endif