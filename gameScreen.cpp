#include "gameScreen.h"

#include <iostream>

GameScreen::GameScreen(sf::RenderWindow& window)//: 
           // mBoard(),//fix
            //mSnake()//fix
{

}


void GameScreen::draw(sf::RenderWindow& window)
{
    window.draw(mBoard);
    window.draw(mSnake);
}



void WelcomeScreen::updateButtons(sf::Event &event, sf::RenderWindow& window)
{
    mBoard.update(event, window);
    mSnake.update(event, window);
}













