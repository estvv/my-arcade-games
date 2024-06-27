#include "colors.hpp"

Colors::Colors(void)
{
}

MenusColors::MenusColors(void) :
    mainColor(sf::Color::Black),
    button(sf::Color::Green),
    buttonText(sf::Color::White),
    buttonHover(sf::Color(0, 150, 0)),
    buttonClicked(sf::Color(0, 100, 0))
{
}

SnakeColors::SnakeColors(void) :
    snakeHead(sf::Color(0, 150, 0)),
    snakeBody(sf::Color(0, 200, 0)),
    apple(sf::Color::Red)
{
}

BreakoutColors::BreakoutColors(void)
{
}

