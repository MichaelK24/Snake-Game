#include "rules.h"

Rules::Rules(sf::RenderWindow& window): backButton("Menu", {300, 700}, {375, 100}, sf::Color::Red)
{
    if (!rulesBackground1.loadFromFile("images/rules.jpeg"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    rulesBackground2.setTexture(rulesBackground1);

}

void Rules::draw(sf::RenderWindow& window)
{
    rulesBackground2.setScale(0.25, 0.25);
    window.draw(rulesBackground2); 
    window.draw(backButton); // Draw the button
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