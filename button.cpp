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
}

void Button::update(sf::Event &e, sf::RenderWindow &window)
{
//    //     //get position of the mouse
    // sf::Vector2i mPos = sf::Mouse::getPosition(window);
    // sf::Vector2f mousePosition =window.mapPixelToCoords(mPos);
    // bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
    //                         && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
    //                         && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
    //                         && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    // if(e.type == sf::Event::MouseMoved)
    // {
    //     if(mouseInButton)
    //     {
    //         mText.setFillColor(mTextHover);
    //     }
    //     else
    //     {
    //         mText.setFillColor(mTextNormal);
    //     }
    // }
    // if (e.type == sf::Event::MouseButtonPressed)
    // {
    //     if(e.mouseButton.button==sf::Mouse::Left)
    //     {
    //         if(mouseInButton)
    //         {
    //             mButton.setRotation(180);
    //         }
    //         else
    //         {
    //             mButton.setRotation(0);
    //         }
    //     }
    // }
    // if (e.type == sf::Event::MouseButtonReleased)
    // {
    //     if (e.mouseButton.button==sf::Mouse::Left)
    //     {
    //         if(mouseInButton)
    //         {
    //             mText.setFillColor(mTextHover);
    //             mButton.setRotation(0);
    //         }
    //         else
    //         {
    //             mText.setFillColor(mTextNormal);
    //             mButton.setRotation(0);
    //         }
    //     }
    // }
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


// /**
//  * @brief Constructor that initializes the button with the given label (s), position (position), size (size), and color (color).
//  * 
//  * @param s 
//  * @param position 
//  * @param size 
//  * @param color 
//  * @return ** Button:: 
//  */
// Button:: Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
// {
//     if (!mTexture.loadFromFile("button.png"))
//     {
//         std::cout<<"Error opening file\n";
//         exit(1);
//     }
//     //create sprite that look like a button
//      mButton.setTexture(mTexture);
    
//     //get size of image
//     sf::Vector2u imageSize=mTexture.getSize();
//     //change origin to the center of the image (makes rotation easy)
//     mButton.setOrigin(imageSize.x/2, imageSize.y/2);
//     //set position
//     mPosition=position;

//     // mPosition.x=300;
//     // mPosition.y=200;
//     mButton.setPosition(mPosition.x,mPosition.y);

//     //choose color

//     mButton.setColor(color);

//     //set size as a ration of original size

//     mButton.setScale(size.x/imageSize.x,size.y/imageSize.y);//percentage of original


//     //Make label

//     if (!mFont.loadFromFile("college.ttf"))
//     {
//         std::cout<<"Error opening file\n";
//         exit(2);
//     }

//     mText.setFont(mFont);
//     //choose the font size based on button size (I choose half)
//     unsigned int fontSize = mButton.getGlobalBounds().height/2;
//     mText.setCharacterSize(fontSize);
//     //set label
//     mText.setString(s);
//     //set origin to the middle
//     mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
//     //set position at the middle of the button
//     mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
//     //choose colors
//     mTextNormal = sf::Color::Green;
//     mTextHover = sf::Color::Red;
//     mText.setFillColor(mTextNormal);
// }

// /**
//  * @brief This function updates the state of the button 
//  * 
//  * @param e 
//  * @param window 
//  * @return ** void 
//  */
// void Button:: update(sf::Event& e, sf::RenderWindow& window)
// {
            
//     //get position of the mouse
//     sf::Vector2i mPos = sf::Mouse::getPosition(window);
//     sf::Vector2f mousePosition =window.mapPixelToCoords(mPos);
//     bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
//                             && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
//                             && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
//                             && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
//     if(e.type == sf::Event::MouseMoved)
//     {
//         if(mouseInButton)
//         {
//             mText.setFillColor(mTextHover);
//         }
//         else
//         {
//             mText.setFillColor(mTextNormal);
//         }
//     }
//     if (e.type == sf::Event::MouseButtonPressed)
//     {
//         if(e.mouseButton.button==sf::Mouse::Left)
//         {
//             if(mouseInButton)
//             {
//                 mButton.setRotation(180);
//             }
//             else
//             {
//                 mButton.setRotation(0);
//             }
//         }
//     }
//     if (e.type == sf::Event::MouseButtonReleased)
//     {
//         if (e.mouseButton.button==sf::Mouse::Left)
//         {
//             if(mouseInButton)
//             {
//                 mText.setFillColor(mTextHover);
//                 mButton.setRotation(0);
//             }
//             else
//             {
//                 mText.setFillColor(mTextNormal);
//                 mButton.setRotation(0);
//             }
//         }
//     }
//  }
    
// /**
//  * @brief This function is used to draw the button onto the given target
//  * 
//  * @param target 
//  * @param states 
//  * @return ** void 
//  */
// void Button:: draw(sf::RenderTarget& target,sf::RenderStates states) const
// {
//     target.draw(mButton,states);
//     target.draw(mText,states);
// }

// /**
//  * @brief constructor
//  * 
//  */
// Button::Button():Button("Push me!",{300,100},{100,100},sf::Color::White)
// {


//     mButton.setScale(1,1);
//     mBtnState = normal;
// }

// /**
//  * @brief This function sets the text label of the button to the given string
//  * 
//  * @param s 
//  * @return ** void 
//  */
// void Button::setText(std::string s)
// {
//     mText.setString(s);
//     mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
//     //set position at the middle of the button
//     unsigned int fontSize = mButton.getGlobalBounds().height/2;
//     mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    
// }
// /**
//  * @brief This function sets the position of the button to the given position
//  * 
//  * @param position 
//  * @return ** void 
//  */
// void Button::setPosition(sf::Vector2f position)
// {
//     mPosition= position;
//     mButton.setPosition(mPosition.x, mPosition.y);
//     unsigned int fontSize=mButton.getGlobalBounds().height/2;
//     mText.setPosition(mPosition.x, mPosition.y -fontSize/4);
// }

// /**
//  * @brief This function sets the size of the button to the given size and adjusts the size of the text to keep it proportional to the button size.
//  * 
//  * @param size 
//  * @return ** void 
//  */
// void Button::setSize(sf::Vector2f  size)
// {
    
//     sf::Vector2u imageSize=mTexture.getSize();
//     mButton.setScale(size.x/imageSize.x,size.y/imageSize.y);
//     mButton.setScale(size.x/imageSize.x,size.y/imageSize.y);//percentage of original

//     unsigned int fontSize = mButton.getGlobalBounds().height/2;
//     mText.setCharacterSize(fontSize);

//     mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
// }
// /**
//  * @brief This function sets the color of the button to the given btnColor.
//  * 
//  * @param btnColor 
//  * @return ** void 
//  */
// void Button::setColor(sf::Color btnColor)
// {
//     mButtonColor = btnColor;
//     mButton.setColor(mButtonColor);

// }

