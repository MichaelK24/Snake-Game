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

Snake::Snake(sf::RenderWindow& window)
{
    start();

    for (int i = 0; i <17; i++){
        for (int j = 0; j <17; j++)
        {
            array[i][j].setSize({TileWidth, TileWidth});
            array[i][j].setPosition(TOP.x +TileWidth*i, TOP.y+TileWidth*j);
            array[i][j].setOrigin(array[i][j].getSize().x/2, array[i][j].getSize().y/2);
            array[i][j].setFillColor(sf::Color::Blue);
        }
    }
}

void Snake::start()
{
    Point initialPosition = {9,9};
    snake.push_back(initialPosition);
    dir = "right";
    score = 0;
    gameOver = false;
}

void Snake::eatApple()
{
    if(board[snake.front().x][snake.front().y] == 'a'){
        Point newBody = snake.back();
        snake.push_back(newBody);
        score++;
        //placeapple(board,score);
    }
}

void Snake::turnInput(sf::RenderWindow& window){
    sf::Event evnt;
    while(window.pollEvent(evnt)){
        if(evnt.type == sf::Event::KeyPressed){
            switch(evnt.key.code){
                case sf::Keyboard::W:
                dir = "up";
                break;
                
                case sf::Keyboard::S:
                dir = "down";
                break;

                case sf::Keyboard::A:
                dir = "left";
                break;

                case sf::Keyboard::D:
                dir = "right";
                break;

                case sf::Keyboard::Escape:
                dir = "end";
                break;
            }
        }
    }

}

void Snake::actualTurn()
{
    Point newH = snake.front();

    if(dir == "up"){
        newH.y++;
        //player.move(0.0,-1 * TileWidth);
    } else if(dir == "down"){
        newH.y--;
        //player.move(0.0,TileWidth);
    } else if(dir == "right"){
        newH.x++;
        //player.move(TileWidth,0.0);
    } else if(dir == "left"){
        newH.x--;
        //player.move(-1 * TileWidth,0.0);
    } else if(dir == "end"){
        gameOver = true;
    }

    if(newH.x > 17 || newH.x < 1 || newH.y > 17 || newH.y < 1){
        gameOver = true;
    }
    //check if snake hits something
}

void Snake::draw(sf::RenderWindow& window){
    for (int i = 0; i<17; i++)
    {
        for (int j = 0; j <17; j++)
        {
            window.draw(array[i][j]);
        }
    }
    
}
//chande colo of array elements based on value of the board elements
void Snake::update()
{
    for (int i = 0; i <17; i++){
        for (int j = 0; j <17; j++)
        {
            switch (board[i][j])
            {
            case 'S':
                array[i][j].setFillColor(sf::Color::Green);
                break;
            case 'A':
                array[i][j].setFillColor(sf::Color::Red);
                break;
            case ' ':
                array[i][j].setFillColor(sf::Color::Black);
                break;
            
            default:
                break;
            }
        }
    }
}

// void Snake::gameOver(){
//     if(function that determines that S touched H || function that determines that S touched ' '){
//         go to end screen;
//     }
// }