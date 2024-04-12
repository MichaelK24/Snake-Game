#include "screen.h"

Screen::Screen(sf::RenderWindow &window) : gameWindow(window)
{
    // Load texture and set up sprite
    if (!texture.loadFromFile("images/snakeScreen.png"))
    {
        // Handle error loading texture
        std::cout << "Error opening file\n";
        exit(1);
    }
    snake.setTexture(texture);

        // Load texture and set up sprite
    if (!background1.loadFromFile("images/menuBackground.jpeg"))
    {
        // Handle error loading texture
        std::cout << "Error opening file\n";
        exit(1);
    }
    background.setTexture(background1);

            // Load texture and set up sprite
    if (!header1.loadFromFile("images/menuHeader.png"))
    {
        // Handle error loading texture
        std::cout << "Error opening file\n";
        exit(1);
    }
    header.setTexture(header1);



}

void Screen::draw()
{

    snake.setPosition(0.f, 50.f);
    snake.setScale(0.65, 0.65);
    background.setPosition(0.f, 0.f);
    background.setScale(1.5, 1.5);
    gameWindow.draw(background);
    gameWindow.draw(snake);
    header.setPosition(450.f, 150.f);
    header.setScale(1.5, 1.5);
    gameWindow.draw(header);


}

