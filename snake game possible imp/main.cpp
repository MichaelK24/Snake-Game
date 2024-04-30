#include "snake.h"
//g++ -Wall *.cpp -o a -lsfml-graphics -lsfml-window -lsfml-system

int main() {
    sf::RenderWindow window(sf::VideoMode(17 * 20, 17 * 20), "Snake Game");
    snake game(window);
    game.run();
    return 0;
}