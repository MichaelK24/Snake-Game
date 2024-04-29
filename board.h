/**
 * @file board.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <string>

class Board {
public:
    Board(sf::RenderWindow& window); // Pass the existing window as a reference
    ~Board(); // Destructor

    //void run();
    void switchToGameOverScreen(); //game over screen 
    void render(sf::RenderWindow& window);

private:
    //sf::RenderWindow& window; // Reference to the existing window
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
    sf::Texture texture1, texture2;
    sf::Sprite sprite1, sprite2;
    sf::Texture appleTexture;
    sf::Sprite appleSprite;
    sf::Texture snakeTexture;
    sf::Sprite snakeSprite;
    sf::Font font;
    sf::Text scoreText, highScoreText, highScoreText1;

    int score;
    int highscore;

    int windowWidth; //
    int windowHeight; 

    const int gridSize;
    const float imageSize;
    float startX, startY;

    // void processEvents();
    // void update(); 
    void releaseResources(); 
};
#endif // BOARD_H

