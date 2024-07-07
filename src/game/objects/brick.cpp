#include "brick.hpp"

Brick::Brick(sf::Color color, sf::Vector2f position, sf::Vector2f size)
{
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setSize(size);
}
