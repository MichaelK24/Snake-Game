#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::RenderWindow& window);
    void handleEvents();
    void update();
    void draw();

private:
    sf::RenderWindow& m_Window;
    sf::Font m_Font;
    sf::Text m_StartText;
    sf::Text m_RulesText;
    sf::Text m_ExitText;
};



#endif