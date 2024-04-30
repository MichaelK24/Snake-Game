#include "gameScreen.h"
#include <unistd.h>


GameScreen::GameScreen(sf::RenderWindow& window) : mBoard(window), mSnake(window) // Assuming mSnake is your game object
{
    score = 0;
    move2 =sf::milliseconds(100);
    // sf::Texture texture;
    // if (!texture.loadFromFile("boardupdat.jpg"))
    // {
    //     std::cout<<"error loading board Texture."<<std::endl;
    // }
    
   // mBackground.setTexture(mTexture);
   // mBackground.setScale(static_cast<float>(window.getSize().x) / mTexture.getSize().x,static_cast<float>(window.getSize().y) / mTexture.getSize().y);
}
void GameScreen::reset()
{
    mSnake.init();
}
void GameScreen::draw(sf::RenderWindow& window)
{
   //window.draw(mBackground);
   mBoard.render(window);
   mSnake.draw(window);
   int score= mSnake.getScore();
   mBoard.setScore(score);
   if (gameOver){
    //draw game over on top
   }
}



void GameScreen::update()
{
    if(move.getElapsedTime() >= move2){
        mSnake.update();
        if(!mSnake.actualTurn()){
            move.restart();
        }
    }
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
        reset();
        gameOver = false;
        return 1;
    }
    
    
}













