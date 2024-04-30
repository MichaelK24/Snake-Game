#include "snake.h"
#include <cstdlib>
#include <ctime>

snake::snake(sf::RenderWindow& window) : window(window) {}

void snake::setup()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    gameOver = false;
    dir = STOP;
    snakeX[0] = width / 2;
    snakeY[0] = height / 2;
    fruitX = std::rand() % width;
    fruitY = std::rand() % height;
    snakeLength = 1;
}

void snake::processInput()
 {
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
            gameOver = true;
        }
        if (event.type == sf::Event::KeyPressed) 
        {
            switch (event.key.code) {
                case sf::Keyboard::A:
                    dir = LEFT;
                    break;
                case sf::Keyboard::D:
                    dir = RIGHT;
                    break;
                case sf::Keyboard::W:
                    dir = UP;
                    break;
                case sf::Keyboard::S:
                    dir = DOWN;
                    break;
                case sf::Keyboard::X:
                    gameOver = true;
                    break;
                default:
                    break;
            }
        }
    }
}

void snake::update() 
{
    if (!gameOver)
    {
        if (dir != STOP) {
            for (int i = snakeLength; i > 0; i--) 
            {
                snakeX[i] = snakeX[i - 1];
                snakeY[i] = snakeY[i - 1];
            }

            switch (dir) 
            {
                case LEFT:
                    snakeX[0]--;
                    break;
                case RIGHT:
                    snakeX[0]++;
                    break;
                case UP:
                    snakeY[0]--;
                    break;
                case DOWN:
                    snakeY[0]++;
                    break;
                default:
                    break;
            }

            if (snakeX[0] == fruitX && snakeY[0] == fruitY) 
            {
                snakeLength++;
                fruitX = std::rand() % width;
                fruitY = std::rand() % height;
            }

            if (snakeX[0] >= width || snakeX[0] < 0 || snakeY[0] >= height || snakeY[0] < 0) 
            {
                gameOver = true;
            }

            for (int i = 1; i < snakeLength; i++) 
            {
                if (snakeX[i] == snakeX[0] && snakeY[i] == snakeY[0]) 
                {
                    gameOver = true;
                    break;
                }
            }
        }
    }
}

void snake::render() 
{
    window.clear();

    sf::RectangleShape fruit(sf::Vector2f(20, 20));
    fruit.setFillColor(sf::Color::Red);
    fruit.setPosition(fruitX * 20, fruitY * 20);
    window.draw(fruit);

    sf::RectangleShape snakeSegment(sf::Vector2f(20, 20));
    snakeSegment.setFillColor(sf::Color::Green);
    for (int i = 0; i < snakeLength; i++) 
    {
        snakeSegment.setPosition(snakeX[i] * 20, snakeY[i] * 20);
        window.draw(snakeSegment);
    }

    window.display();
}

void snake::run() 
{
    setup();
    while (window.isOpen() && !gameOver) 
    {
        processInput();
        update();
        render();
        sf::sleep(sf::milliseconds(100));
    }
}