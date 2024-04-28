#include "gameScreen.h"


GameScreen::GameScreen(sf::RenderWindow& window) : mSnake(window) // Assuming mSnake is your game object
{
    sf::Texture texture;
    if (!texture.loadFromFile("boardupdat.jpg"))
    {
        std::cout<<"error loading board Texture."<<std::endl;
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(static_cast<float>(window.getSize().x) / texture.getSize().x,static_cast<float>(window.getSize().y) / texture.getSize().y);
    window.draw(sprite);
}

void GameScreen::draw(sf::RenderWindow& window)
{
   mSnake.draw(window);
}



void GameScreen::update()
{
    mSnake.update();
}

void GameScreen::handleInput(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) 
    { 
        if (event.key.code == sf::Keyboard::Right) 
        { 
            std::cout << "right arrow key WAS pressed\n"; 
        } 
    }
}













