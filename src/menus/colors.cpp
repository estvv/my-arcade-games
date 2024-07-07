#include "colors.hpp"

using namespace std;

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

BubbleShooterColors::BubbleShooterColors(void)
{
}

ObjectsColors::ObjectsColors(void)
{
    ballColors.push_back(sf::Color::Green);
    ballColors.push_back(sf::Color::Yellow);
    ballColors.push_back(sf::Color::Blue);
    ballColors.push_back(sf::Color::Magenta);
    ballColors.push_back(sf::Color::Red);
    ballColors.push_back(sf::Color::Cyan);
    srand(static_cast<unsigned>(time(0)));
}

sf::Color ObjectsColors::getRandomObjectColor(vector<sf::Color> objects)
{
    return objects[rand() % objects.size()];
}
