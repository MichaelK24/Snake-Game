#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include <iostream>
#include "welcomeScreen.h"
#include "gameScreen.h"
#include "rules.h"
// #include "button.h"

class Game
{
public:
    Game();
    ~Game(){};
    void handleInput(sf::Event &event);
    void update();
    void render();
    bool isDone() const;
private:
    sf::RenderWindow  mWindow;
    WelcomeScreen screen1;
    GameScreen screen2;
    Rules screen3;
    int screen;
    bool mIsDone;

};

#endif