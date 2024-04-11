#include "screen.h"

Screen::Screen(sf::RenderWindow &window) : gameWindow(window)
{
    // Load texture and set up sprite
    if (!texture.loadFromFile("images/snakeScreen.png"))
    {
        // Handle error loading texture
    }
    snake.setTexture(texture);
}

void Screen::draw()
{
    snake.setPosition(0.f, 50.f);
    gameWindow.draw(snake);
}

