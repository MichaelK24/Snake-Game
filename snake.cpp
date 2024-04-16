/**
 * @file snake.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "snake.h"
#include "board.h"

Snake::Snake(Board myBoard)
{
    this->myBoard = myBoard;
    //Board b; 
    lastMove = "right";
    start();
}

void Snake::start()
{
    int startingLength = 3;
    int initialColumn = 10;
    int intialRow = 10;
    for(int i = 0; i < startingLength; i++)
    {
        snake.push_back('s');
    }

}

// void Snake::eatApple()
// {
//     if(){
//         score++;
//         snake.pushback(snakeBody);
//     }
// }

void Snake::turnInput(){
    keypad(stdscr,TRUE);
    char c = getch();
    if(c == 'w'){
        dir = "up";
    } else if(c == 's'){
        dir = "down";
    } else if(c == 'a'){
        dir = "left";
    } else if(c == 'd'){
        dir == "right";
    } else if(c == 'x'){
        gameOver = true;
    }
}

char* Snake::actualTurn()
{
    // After turnInput function we will initialize a char pointer variable called temp to be equal to the function actualTurn()
    // Initialize char * called and set it equal to vector[0]. 
}



// void Snake::gameOver(){
//     if(function that determines that S touched H || function that determines that S touched ' '){
//         go to end screen;
//     }
// }