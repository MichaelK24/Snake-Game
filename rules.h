
#ifndef RULES_H
#define RULES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "welcomeScreen.h"
#include "button.h"

class Rules
{
public:
    Rules(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    // void handleInput(sf::Event &event, sf::RenderWindow& window);
    int handleInput(sf::Event &event, sf::RenderWindow& window);
    void updateButtons();

private:
    sf::Texture texture;
    sf::Texture rulesBackground1;
    sf::Sprite rulesBackground2;
    Button backButton;
    // sf::Font font;

};

#endif