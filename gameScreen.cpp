#include "gameScreen.h"


GameScreen::GameScreen(sf::RenderWindow& window) : mSnake(window) // Assuming mSnake is your game object
{
    if (!mTexture.loadFromFile("images/boardupdat.jpg"))
    {
        std::cout<<"error loading board Texture."<< std::endl;
    }
    // if (!texture.loadFromFile("images/snakeScreen.png"))
    // {
    //     std::cout << "Error opening file\n";
    //     exit(1);
    // }
    
    mBackground.setTexture(mTexture);
    mBackground.setScale(static_cast<float>(window.getSize().x) / mTexture.getSize().x,static_cast<float>(window.getSize().y) / mTexture.getSize().y);
}

void GameScreen::draw(sf::RenderWindow& window)
{
   window.draw(mBackground);
   mSnake.draw(window);
   if (gameOver){
    //draw game over on top
   }
}



void GameScreen::update()
{
    mSnake.update();
}

int GameScreen::handleInput(sf::Event &event)
{
    // if (event.type == sf::Event::KeyPressed) 
    // { 
    //     if (event.key.code == sf::Keyboard::Right) 
    //     { 
    //         //std::cout << "right arrow key WAS pressed\n"; 
            
    //     } 
    // }
    if (!gameOver){
       mSnake.turnInput(event); 
       gameOver = mSnake.actualTurn();
       return 2;//stil in game
    }else{
        //check if user press anithing
        return 1;
    }
    
    
}













