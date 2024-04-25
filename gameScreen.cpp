#include "gameScreen.h"


GameScreen::GameScreen(sf::RenderWindow& window):mSnake(window)//fix
{
    
}


void GameScreen::draw(sf::RenderWindow& window)
{
   mSnake.draw(window);
}



void GameScreen::update(sf::RenderWindow& window)
{
    //mBoard.update(event, window);
    mSnake.update();
    mSnake.turnInput(window);
    mSnake.actualTurn();
}

void GameScreen::handleInput(sf::Event &event){
    if (event.type == sf::Event::KeyPressed) 
            { 
                if (event.key.code == sf::Keyboard::Right) 
                { 
                    std::cout << "right arrow key WAS pressed\n"; 
                } 
            }
}













