/**
 * @file gameover.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gameover.h"
#include "button.h"

gameover::gameover(sf::RenderWindow& window): backButton("MENU", {700, 700}, {375, 100}, sf::Color::Red)
{
    if (!texture.loadFromFile("images/Gameover.png")) {
        exit(1); 
    }

    gameoverscreen.setTexture(texture);
    gameoverscreen.setScale(2.00f, 2.00f);
    gameoverscreen.setPosition(350,-200);
}

void gameover::draw(sf::RenderWindow& window)
{
    window.draw(gameoverscreen); 
    window.draw(backButton); // Draw the button
}

void gameover::updateButtons()
{
    backButton.update();
}

int gameover::handleInput(sf::Event &event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        // Check if the play again button is clicked
        if (backButton.handleInput(event, window))
        {
            // Return value to indicate play again action
            return 1;
        }
    }
    return -1;
}