

#include "board.h"
// Board::Board()
// {

// }
// void Board::setupboard(char array[size][size]) 
// {
//     for(int i = 0; i < size; i++) 
//     {
//         for(int j = 0; j < size; j++) 
//         {
//             array[i][j] = ' ';
//         }
//     }
// }
// void Board::placeapple(char array[size][size],int score)
// {
//     srand (time(NULL));
//     int row,col;
//     do
//     {
//         row= rand()%17+1;
//         col= rand()%17+1;
//     }while(array[row][col]!=' ');
//     array[row][col]='A';
// }
// void Board::displayboard(char array[size][size])
// {
//     for(int i=0;i<size;i++)
//     {
//         for(int j=0;j<size;j++)
//         {
//             std::cout<<array[i][j];
//         }
//         cout<<std::endl;
//     }
// }

/**
 * @file board.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

Board::Board(sf::RenderWindow& window) :
    //window(existingWindow),
    //bgTexture(), 
    gridSize(14),
    imageSize(40.0f) {
    if (!bgTexture.loadFromFile("images/green.jpg") || 
        !texture1.loadFromFile("images/lightgreen.jpg") || 
        !texture2.loadFromFile("images/darkgreen.png") || 
        !appleTexture.loadFromFile("images/apple.png") || 
        !snakeTexture.loadFromFile("images/snakeScreen.png")) {
        return;
    }
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(2.00f,2.00f);

    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite2.setScale(1.50f, 1.50f);
    sprite1.setScale(1.50f, 1.50f);

    appleSprite.setTexture(appleTexture);
    appleSprite.setScale(0.09f, 0.09f);

    snakeSprite.setTexture(snakeTexture);
    snakeSprite.setScale(2.0f, 2.0f);
    snakeSprite.setPosition(-500.0f, -1050.0f);

    font.loadFromFile("arial.ttf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::White);

    highScoreText1.setFont(font);
    highScoreText1.setCharacterSize(24);
    highScoreText1.setFillColor(sf::Color::White);

    startX = (bgTexture.getSize().x - gridSize * imageSize) / 3.1f;
    startY = (bgTexture.getSize().y - gridSize * imageSize) / 5.0f;
}

Board::~Board() 
{
    releaseResources();
}

// void Board::run() 
// {
//     while (window.isOpen()) {
//         processEvents();
//         update();
//         render();
//     }
// }

// void Board::processEvents() 
// {
//     sf::Event event;
//     while (window.pollEvent(event)) 
//     {
//         if (event.type==sf::Event::Closed) {
//             window.close();
//         }
//     }
// }

// void Board::update() 
// {

// }

void Board::render(sf::RenderWindow& window) 
{
    //window.clear();

    window.draw(bgSprite);
    window.draw(snakeSprite);

    if(score>highscore)
    {
        highscore=score;
    }
    scoreText.setString("Score");
    scoreText.setPosition(30.0f*1.75f,150.0* 1.333333f);
    window.draw(scoreText);

    scoreText.setString(std::to_string(score));
    scoreText.setPosition(45.0f*1.75f,180.0f*1.333333f);
    window.draw(scoreText);

    scoreText.setString(std::to_string(highscore));
    scoreText.setPosition(746.0f * 1.75f, 180.0f * 1.333333f);
    window.draw(scoreText);

    highScoreText.setString("High");
    highScoreText.setPosition(735.0f * 1.75f, 125.0f * 1.333333f);
    window.draw(highScoreText);

    highScoreText1.setString("Score");
    highScoreText1.setPosition(732.0f * 1.75f, 150.0f * 1.333333f);
    window.draw(highScoreText1);

    appleSprite.setPosition(0.0f * 1.75f, 0.0f * 1.333333f);
    window.draw(appleSprite);
    appleSprite.setPosition(700.0f * 1.75f, 0.0f * 1.333333f);
    window.draw(appleSprite);
    appleSprite.setPosition(0.0f * 1.75f, 500.0f * 1.333333f);
    window.draw(appleSprite);
    appleSprite.setPosition(700.0f * 1.75f, 500.0f * 1.333333f);
    window.draw(appleSprite);

    //window.display();
}

void Board::releaseResources() {
    // bgTexture.~Texture();
    // texture1.~Texture();
    // texture2.~Texture();
    // appleTexture.~Texture();
    // snakeTexture.~Texture();
}

