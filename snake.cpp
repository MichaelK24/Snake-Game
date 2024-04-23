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

Snake::Snake(Board myBoard) : myBoard(myBoard)
{
    dir = "right";
    score = 0;
    gameOver = false;
    start();
}

void Snake::start()
{
    Point initialPosition = {9,9};
    snake.push_back(initialPosition);
    myBoard.board[initialPosition.x][initialPosition.y] = 'S';
}

void Snake::eatApple()
{
    if(myBoard.board[snake.front().x][snake.front().y] == 'a'){
        Point newBody = snake.back();
        snake.push_back(newBody);
        score++;
        myBoard.placeapple(board,score);
    }
}

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

void Snake::actualTurn()
{
    // After turnInput function we will initialize a char pointer variable called temp to be equal to the function actualTurn()
    // Initialize char * called and set it equal to vector[0]. Code is on phone.
    Point* ret = snake.front();
    Point newH = ret;
    if(dir == "up"){
        newH.y++;
    } else if(dir == "down"){
        newH.y--;
    } else if(dir == "right"){
        newH.x++;
    } else if(dir == "left"){
        newH.x--;
    }
    snake.push_front(newH);
    snake.pop_back();
}



// void Snake::gameOver(){
//     if(function that determines that S touched H || function that determines that S touched ' '){
//         go to end screen;
//     }
// }