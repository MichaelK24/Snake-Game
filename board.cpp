/**
 * @file board.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "board.h"
Board::Board()
{
    char board[size][size];
}
void Board::setupboard(char array[size][size],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            array[i][j]='  ';
        }
    }
}
void Board::placeapple(char array[size][size],int score)
{
    srand (time(NULL));
    int row,col;
    do
    {
        row= rand()%17+1;
        col= rand()%17+1;
    }while(array[row][col]!='  ');
    array[row][col]=='a';
}
void Board::displayboard(char array[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            std::cout<<array[i][j];
        }
        cout<<std::endl;
    }
}

//even integers dark green odd are light green.