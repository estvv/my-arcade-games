#include "cell.hpp"

Cell::Cell(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColor, sf::Color outlineColor, float thickness)
{
    cell.setFillColor(fillColor);
    cell.setPosition(pos);
    cell.setSize(size);
    cell.setOutlineThickness(thickness);
    cell.setOutlineColor(outlineColor);
}
