/**
 * @file Rules.cpp
 * @author Yolexis Rodriguez
 * @brief This File implement the Rules screen that explain the instructions of the game and goes back to welcome screen
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */

#include "rules.h"

Rules::Rules(sf::RenderWindow& window): backButton("MENU", {300, 700}, {375, 100}, sf::Color::Red)
{
    if (!rulesBackground1.loadFromFile("images/rules.jpeg"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }

        // Load the font
    if (!font.loadFromFile("font.ttf"))
    {
        std::cout << "Error loading font\n";
        exit(1);
    }

    // sf::Text text;
    text.setFont(font);
    text.setString( "\nRULES:\n"
                    "- USE THE W KEY TO MOVE UP.\n"
                    "- USE THE S KEY TO MOVE DOWN.\n"
                    "- USE THE D KEY TO MOVE RIGHT.\n"
                    "- USE THE A KEY TO MOVE LEFT.\n\n"
                    "EAT THE RED SQUARE TO GROW LONGER.\n\n" 
                    "AVOID HITTING THE WALLS OR THE SNAKE'S BODY.\n"
   
                    "TIP: PLAN YOUR MOVE AHEAD TO AVOID\n" 
                    "TRAPPING THE SNAKLE!");

    text.setCharacterSize(20);
    text.setFillColor(sf::Color(204,102,0));
    text.setPosition(320, 150); // Adjust position as needed


    rulesBackground2.setTexture(rulesBackground1);
    rulesBackground2.setScale(0.25, 0.25);

}

void Rules::draw(sf::RenderWindow& window)
{
    window.draw(rulesBackground2); 
    window.draw(backButton); // Draw the button
    window.draw(text);
    //textTexture.display();
}
void Rules::updateButtons()
{
    backButton.update();
}
int Rules::handleInput(sf::Event &event, sf::RenderWindow& window)
{
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // Check if any of the buttons are clicked
            if(backButton.handleInput(event, window))
            {
                // Change the screen to screen 2, game
                return 1;
            }
        }
        return -1;
}
// Snake Game Instructions:

// Use the W key to move up.
// Use the S key to move down.
// Use the D key to move right.
// Use the A key to move left.
// Objective: Eat the food (red square) to grow longer. Avoid hitting the walls or the snake's own body.

// Controls: Use the arrow keys or WASD keys to control the snake's direction.

// Tip: Plan your moves ahead to avoid trapping the snake!


