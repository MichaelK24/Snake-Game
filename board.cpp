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

}
void Board::setupboard(char array[size][size]) 
{
    for(int i = 0; i < size; i++) 
    {
        for(int j = 0; j < size; j++) 
        {
            array[i][j] = ' ';
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
    }while(array[row][col]!=' ');
    array[row][col]=='A';
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
bool Board::greenblue(int row,int col)
{
    if(col%2==1)
    {
        if(row%2==0)
        {
            return true;

        }else
        {
            return false;
        }
    
    }else
    if(row%2==0)
    {
        return false;
    }else
    {
        return true;
    }
}

