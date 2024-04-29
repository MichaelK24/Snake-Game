/**
 * @file button.cpp
 * @author Yolexis Rodriguez
 * @brief this functions handle the buttons ojn the welcome screen and rules screen
 * @date 04/29/2024
 * 
 * Compiler for mac  g++ -std=c++11 *.cpp -I /opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 */
#include "button.h"


Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("images/button.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);

    //get size of image
    sf::Vector2u imageSize = mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x / 2, imageSize.y / 2);
    //set position
    mPosition = position;
    mButton.setPosition(mPosition.x, mPosition.y);

    //choose color
    mButton.setColor(color);

    //set size as a ratio of original size
    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y); //percentage of original

    // Make label
    if (!mFont.loadFromFile("font.ttf"))
    {
        std::cout << "Error opening file\n";
        exit(2);
    }

    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = (mButton.getGlobalBounds().height / 2)-5;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 8);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Green;
    mText.setFillColor(mTextNormal);
    mState = normal;
}

bool Button::handleInput(sf::Event &e, sf::RenderWindow& window)
{
//    //     //get position of the mouse
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition =window.mapPixelToCoords(mPos);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            //mText.setFillColor(mTextHover);
            mState= hovered;
        }
        else
        {
            //mText.setFillColor(mTextNormal);
            mState = normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                //mButton.setRotation(180);
                mState = clicked;
                return true;
            }
            else
            {
                //mButton.setRotation(0);
                mState = normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mState = hovered;
                //mText.setFillColor(mTextHover);
                //mButton.setRotation(0);
            }
            else
            {
                mState = normal;
                // mText.setFillColor(mTextNormal);
                // mButton.setRotation(0);
            }
        }
    }
    return false;
}
void Button::update(){
    switch (mState)
    {
    case normal:
            mText.setFillColor(mTextNormal);
            mButton.setRotation(0);
        break;
    case hovered:
            mText.setFillColor(mTextHover);
            mButton.setRotation(0);
        break;
    case clicked:
            mText.setFillColor(mTextHover);
            mButton.setRotation(180);
        break;
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

void Button::setText(std::string s)
{
    mText.setString(s);
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    //set position at the middle of the button
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
}

void Button::setPosition(sf::Vector2f position)
{
    mPosition = position;
    mButton.setPosition(mPosition.x, mPosition.y);
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
}

void Button::setSize(sf::Vector2f size)
{
    sf::Vector2u imageSize = mTexture.getSize();
    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y);
    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y); //percentage of original

    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);

    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
}

void Button::setColor(sf::Color btnColor)
{
    mButtonColor = btnColor;
    mButton.setColor(mButtonColor);
}



