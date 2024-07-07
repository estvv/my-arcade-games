#include "arena.hpp"
#include "enum.hpp"

Arena::Arena(sf::Vector2f size, sf::Vector2f pos)
{
    initArena(size, pos);
}

// Init of the arena for the game
void Arena::initArena(sf::Vector2f size, sf::Vector2f pos)
{
    arena.setSize(size);
    arena.setOutlineThickness(2);
    arena.setOutlineColor(sf::Color(0, 240, 0));
    arena.setPosition(pos);
    arena.setFillColor(sf::Color::Transparent);
}

// Draw arena and each cells in it
void Arena::drawArena(sf::RenderWindow &window)
{
    sf::RectangleShape cell;
    int pos_x = arena.getPosition().x;
    int pos_y = arena.getPosition().y;

    cell.setSize(sf::Vector2f(20, 20));
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color(100, 100, 100));
    cell.setFillColor(sf::Color::Transparent);
    for (int y = pos_y; y < pos_y + arena.getSize().y; y += 20) {
        for (int x = pos_x; x < pos_x + arena.getSize().x; x += 20) {
            cell.setPosition(sf::Vector2f(x, y));
            window.draw(cell);
        }
    }
    window.draw(arena);
}
