#include "game.h"

Game::Game() : mWindow(sf::VideoMode(2000, 1000), "SFML works!"), screen1(mWindow), screen2(mWindow) 
{
    screen = 2;//set to 2 to test snake
    mIsDone = false;
}
//Handle events from input devices and the window
void Game::handleInput(sf::Event &event)
{
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Close window button clicked.
            mWindow.close();
        }
        //call handel input for difrent screens
        switch(screen){
            //case 1: 
            case 2: screen2.handleInput(event);
                break;
        }

    }
}

void Game::update(sf::Event event)
{
    switch (screen)
    {
    case 1:
        screen1.updateButtons(event, mWindow);
        break;
    case 2:
       screen2.update(mWindow);
       break;
    }
    // case 2:
    // //screeen2,update
    
    // default:
    //     break;
    // }  
}

bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}

void Game::render()
{
    mWindow.clear();
    switch(screen)
    {
        case 1: screen1.draw(mWindow);
            break;
        case 2: screen2.draw(mWindow);
            break;
    }
        
    
    mWindow.display();
}
