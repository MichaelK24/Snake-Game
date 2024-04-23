#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "snake.h"
#include <iostream>
#include "welcomeScreen.h"
//#include "gameScreen.h"
// #include "button.h"

class Game
{
public:
    Game();
    ~Game(){};
    void handleInput(sf::Event &event);
    void update(sf::Event event);
    void render();
    bool isDone() const;
private:
    sf::RenderWindow  mWindow;
    WelcomeScreen screen1;
    //GameScreen screen2;
    int screen;
    bool mIsDone;
    // sf::Texture mTextureTile;
    // sf::CircleShape mCherryPlant;
    // sf::Vector2i mIncrement;
    // void moveCherry();

};

#endif