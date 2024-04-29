/**
 * @file game.h
 * @author Yolexis Rodriguez (created the set up)
 * @brief This use a guard code and implement the functions prototypes
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */
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