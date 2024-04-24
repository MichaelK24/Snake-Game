#include "welcomeScreen.h"

#include <iostream>

WelcomeScreen::WelcomeScreen(sf::RenderWindow& window): 
            button3("START", {300, 700}, {375, 100}, sf::Color::Red),
            button2("RULES", {700, 700}, {375, 100}, sf::Color::Red),
            button1("EXIT", {1100, 700}, {375, 100}, sf::Color::Red) //: mWindow(window)
{
    if (!texture.loadFromFile("images/snakeScreen.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    snake.setTexture(texture);

    if (!background1.loadFromFile("images/menuBackground.jpeg"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    background.setTexture(background1);

    if (!header1.loadFromFile("images/menuHeader.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
std::cout<<texture.getSize().x<<std::endl;
    background.setScale(2000/texture.getSize().x, 1000/texture.getSize().y);
    
    header.setTexture(header1);

    // Button button3("START", {300, 700}, {375, 100}, sf::Color::Red);
    // button2 = Button("RULES", {700, 700}, {375, 100}, sf::Color::Red);
    // button1 = Button("EXIT", {1100, 700}, {375, 100}, sf::Color::Red);
}

// void WelcomeScreen::draw()
// {
//     snake.setPosition(0.f, 50.f);
//     snake.setScale(0.65, 0.65);
//     background.setPosition(0.f, 0.f);
//     background.setScale(1.5, 1.5);
//     gameWindow.draw(background);
//     gameWindow.draw(snake);
//     header.setPosition(450.f, 150.f);
//     header.setScale(1.5, 1.5);
//     gameWindow.draw(header);
// }

void WelcomeScreen::draw(sf::RenderWindow& window)
{
//TODO: Move all sets to constructor.
    snake.setPosition(0.f, 50.f);
    snake.setScale(0.65, 0.65);
    //background.setScale(1.5, 1.5);
    window.draw(background); // Use mWindow instead of gameWindow
    window.draw(snake);       // Use mWindow instead of gameWindow
    header.setPosition(450.f, 150.f);
    header.setScale(1.5, 1.5);
    window.draw(header);      // Use mWindow instead of gameWindow
    window.draw(button3);
    window.draw(button2);
    window.draw(button1);
}
// void WelcomeScreen::updateButtons(sf::Event &event)
// {
//     button1.update(event, mWindow);
//     button2.update(event, mWindow);
//     button3.update(event, mWindow);
// }


void WelcomeScreen::updateButtons(sf::Event &event, sf::RenderWindow& window)
{
    button1.update(event, window);
    button2.update(event, window);
    button3.update(event, window);
}

// #include "screen.h"

// Screen::Screen(sf::RenderWindow &window) : gameWindow(window)
// {
//     // Load texture and set up sprite
//     if (!texture.loadFromFile("images/snakeScreen.png"))
//     {
//         // Handle error loading texture
//         std::cout << "Error opening file\n";
//         exit(1);
//     }
//     snake.setTexture(texture);

//         // Load texture and set up sprite
//     if (!background1.loadFromFile("images/menuBackground.jpeg"))
//     {
//         // Handle error loading texture
//         std::cout << "Error opening file\n";
//         exit(1);
//     }
//     background.setTexture(background1);

//             // Load texture and set up sprite
//     if (!header1.loadFromFile("images/menuHeader.png"))
//     {
//         // Handle error loading texture
//         std::cout << "Error opening file\n";
//         exit(1);
//     }
//     header.setTexture(header1);

// }

// void Screen::draw()
// {

//     snake.setPosition(0.f, 50.f);
//     snake.setScale(0.65, 0.65);
//     background.setPosition(0.f, 0.f);
//     background.setScale(1.5, 1.5);
//     gameWindow.draw(background);
//     gameWindow.draw(snake);
//     header.setPosition(450.f, 150.f);
//     header.setScale(1.5, 1.5);
//     gameWindow.draw(header);

// }











