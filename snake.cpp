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

Snake::Snake(sf::RenderWindow& window)
{
    
    initBoard();
    board[7][7] = 'S';
    board[11][7] = 'A';

    Point initialPosition = {7,7};
    snake.push_back(initialPosition);
    dir = " ";
    score = 0;
    gameOver = false;
    update();

    for (int i = 0; i <17; i++){
        for (int j = 0; j <17; j++)
        {
            array[i][j].setSize({TileWidth, TileWidth});
            array[i][j].setPosition(TOP.x + TileWidth*i+35, TOP.y + TileWidth*j+35);
            array[i][j].setOrigin(array[i][j].getSize().x/2, array[i][j].getSize().y/2);
            array[i][j].setFillColor(sf::Color::Blue);
            array[i][j].setOutlineThickness(1);
            array[i][j].setOutlineColor(sf::Color::Red);
        }
    }
}
void Snake::initBoard()
{
    for (int i = 0; i <17; i++){
        for (int j = 0; j <17; j++)
        {
            board[i][j] = ' ';
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
                array[i][j].setFillColor(sf::Color::Green);//make duck green
                break;
            case 'A':
                array[i][j].setFillColor(sf::Color::Red);
                break;
            case 's':
                array[i][j].setFillColor(sf::Color::Green);
                break;           
            default:
                array[i][j].setFillColor(sf::Color::Blue);
            }
        }
    }
}

// void Snake::eatApple()
// {
//     if(board[snake.front().x][snake.front().y] == 'A'){
//         Point newBody = snake.back();
//         snake.push_back(newBody);
//         score++;
//         //placeapple(board,score);
//     }
// }

void Snake::turnInput(sf::Event &evnt){
    //while(window.pollEvent(evnt)){
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
    //}

}

bool Snake::actualTurn()
{
    Point newH = snake.front();

    if(dir == "up"){
        newH.y--;
        //player.move(0.0,-1 * TileWidth);
    } else if(dir == "down"){
        newH.y++;

        //player.move(0.0,TileWidth);
    } else if(dir == "right"){
        newH.x++;
        //player.move(TileWidth,0.0);
    } else if(dir == "left"){
        newH.x--;
        //player.move(-1 * TileWidth,0.0);
    } else if(dir == "end"){
        //gameOver = true;
        std::cout << "Game Over" << std::endl;
        return true;
    }

    if(newH.x >= 17 || newH.x < 1 || newH.y >= 17 || newH.y < 1){
        //gameOver = true;
        return true;
    }

    for(int i = 0; i < snake.size()-1; i++){
        if(snake[i].x == newH.x && snake[i].y == newH.y){
            std::cout<< "Game Over" << std::endl;
            return true;
        }
    }

    //check if snake hits something
    if(board[newH.x][newH.y] == 'A'){
        score++;
        srand (time(NULL));
        int row,col;
        do
        {
            row= rand()%17;
            col= rand()%17;
        }while(board[row][col] != ' ');
        board[row][col] ='A';
    } else{
        Point old = snake.back();
        snake.pop_back();
        board[old.x][old.y] = ' ';
    }

    snake.insert(snake.begin(),newH);
    board[newH.x][newH.y] = 'S';
    return false;
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


// void Snake::gameOver(){
//     if(function that determines that S touched H || function that determines that S touched ' '){
//         go to end screen;
//     }
// }