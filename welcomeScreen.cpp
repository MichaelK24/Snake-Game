/**
 * @file WelcomeScreen.cpp
 * @author Yolexis Rodriguez
 * @brief Represents the welcome screen of a game and includes buttons for starting the game, viewing the rules, and exiting.
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */

#include "welcomeScreen.h"
#include "board.h"

#include <iostream>

/**
 * @brief Constructor
 * 
 */
WelcomeScreen::WelcomeScreen(sf::RenderWindow& window): 
            button1("START", {300, 700}, {375, 100}, sf::Color::Red),
            button2("RULES", {700, 700}, {375, 100}, sf::Color::Red),
            button3("EXIT", {1100, 700}, {375, 100}, sf::Color::Red) //: mWindow(window)
{
    if (!texture.loadFromFile("images/snakeScreen.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    snake.setTexture(texture);

    if (!background1.loadFromFile("images/menuBackground.jpeg"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    background.setTexture(background1);

    if (!header1.loadFromFile("images/menuHeader.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }

    // background.setScale(2000/texture.getSize().x, 1000/texture.getSize().y);
    
    header.setTexture(header1);
    background.setScale(1.5, 1.5);
    snake.setPosition(0.f, 50.f);
    snake.setScale(0.65, 0.65);
}

/**
 * @brief functions that draw the images to the window
 * 
 * @param window 
 * @return ** void 
 */
void WelcomeScreen::draw(sf::RenderWindow& window)
{
//TODO: Move all sets to constructor.
    window.draw(background); // Use mWindow instead of gameWindow
    window.draw(snake);       // Use mWindow instead of gameWindow
    header.setPosition(450.f, 150.f);
    header.setScale(1.5, 1.5);
    window.draw(header);      // Use mWindow instead of gameWindow
    window.draw(button3);
    window.draw(button2);
    window.draw(button1);
}


void WelcomeScreen::updateButtons()
{
    button1.update();
    button2.update();
    button3.update();
}

/**
 * @brief Function that call handel input for difrent screens
 * 
 * @param event 
 * @param window 
 * @return ** int 
 */
int WelcomeScreen::handleInput(sf::Event &event, sf::RenderWindow& window)
{
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // Check if any of the buttons are clicked
            if(button1.handleInput(event, window))
            {
                // Change the screen to screen 2, game
                return 2;
            }
            else if(button2.handleInput(event, window))
            {
                // Change the screen to screen 3, rules
                return 3;
            }
            else if(button3.handleInput(event, window))
            {
                return 0;
            }
        }
        return -1;
}









