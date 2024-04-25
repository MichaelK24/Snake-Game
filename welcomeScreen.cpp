#include "welcomeScreen.h"

#include <iostream>

WelcomeScreen::WelcomeScreen(sf::RenderWindow& window): 
            button3("START", {300, 700}, {375, 100}, sf::Color::Red),
            button2("RULES", {700, 700}, {375, 100}, sf::Color::Red),
            button1("EXIT", {1100, 700}, {375, 100}, sf::Color::Red) //: mWindow(window)
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
}


void WelcomeScreen::draw(sf::RenderWindow& window)
{
//TODO: Move all sets to constructor.
    snake.setPosition(0.f, 50.f);
    snake.setScale(0.65, 0.65);
    background.setScale(1.5, 1.5);
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

//call handel input for difrent screens
int WelcomeScreen::handleInput(sf::Event &event, sf::RenderWindow& window)
{
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // Check if any of the buttons are clicked
            if(button1.handleInput(event, window))
            {
                // Change the screen to screen 2, for example
                return 2;
            }
            else if(button2.handleInput(event, window))
            {
                // Change the screen to screen 3, for example
                return 3;
            }
            else if(button3.handleInput(event, window))
            {
                return 0;
            }
        }
        return -1;
}









