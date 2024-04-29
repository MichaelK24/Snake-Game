/**
 * @file button.h
 * @author Yolexis Rodriguez
 * @brief this functions huse guard code and implememt functions prototype
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */
#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <SFML/Graphics.hpp>
//  #include "welcomeScreen.h"

enum state {normal, hovered, clicked};

class Button: public sf::Drawable
{
public:

    Button();
    //Constructor that sets button label to s, button position to the position,  button size to size (given in pixels), and button color to color.
    Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~Button(){};
    //change button position to position (what else needs to be changed?)
    void setPosition(sf::Vector2f position);
    //change button size to size (what else needs to be changed?)
    void setSize(sf::Vector2f  size);
    //change button color to color (what else needs to be changed?)
    void setColor(sf::Color btnColor);
    //change button label to s (what else needs to be changed?)
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};
    void setColorTextHover(sf::Color textHoverColor){mTextHover = textHoverColor;};

    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};

    //This function update the button state and/or look
    bool handleInput(sf::Event &e, sf::RenderWindow& window);
    void update();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

    

private:
    sf::Sprite mButton;
    sf::Texture mTexture;
    sf::Color mButtonColor;
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    
    //text
    sf::Text mText;
    sf::Font mFont;
    sf::Color mTextNormal;
    sf::Color mTextHover;
    enum state mState;

};


#endif