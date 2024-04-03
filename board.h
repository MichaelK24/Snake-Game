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
#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
    char array[16][16];
public:
    void update();
    void placeapple();
    void setupboard();

};


#endif