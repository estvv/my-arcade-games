#include "ball.hpp"
#include <cstdlib>
#include <ctime>

Ball::Ball(sf::Color color, sf::Vector2f position, float radius)
{
    shape.setOutlineColor(sf::Color(220, 220, 220));
    shape.setOutlineThickness(3);
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(color);
}
