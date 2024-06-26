#include "game.h"

Game::Game() : mWindow(sf::VideoMode(1400, 800), "SFML works!"), screen1(mWindow), screen2(mWindow), screen3(mWindow), screen4(mWindow)
{
    screen = 1;//set to 2 to test snake
    mIsDone = false;
}

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
        int ret=-1;
        switch(screen)
        {
            case 1:
                ret = screen1.handleInput(event, mWindow);
                 //0 mean game over
                break;

            case 2: 
                ret = screen2.handleInput(event);
                break;
            // case 3: //rules

            case 3: 
                //screen3.handleInput(event);
                ret = screen3.handleInput(event, mWindow); //0 mean game over
                break;
            case 4:
                ret = screen4.handleInput(event, mWindow);
                break;
        }

        if (ret!= -1)
        {
            screen = ret;
        }

    }
}

void Game::update()
{
    switch (screen)
    {
    case 0:
        mIsDone=true;
        break;
    case 1:
        screen1.updateButtons();
        break;
    case 2:
       screen2.update();
       break;
    case 3:
       screen3.updateButtons();
       break;
    case 4:
       screen4.updateButtons();
       break;
    } 
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
        case 3: screen3.draw(mWindow);
            break;  
        case 4: screen4.draw(mWindow);
            break;
    }
        
    
    mWindow.display();
}