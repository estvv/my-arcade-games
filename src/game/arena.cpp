#include "arena.hpp"
#include "enum.hpp"

Arena::Arena(sf::Vector2f size, sf::Vector2f pos) :
    arenaCell(size, pos, sf::Color::Transparent, sf::Color(0, 240, 0), 2)
{
}

// Draw arena and each cells in it
void Arena::drawArena(sf::RenderWindow &window)
{
    Cell cell(sf::Vector2f(20, 20), sf::Vector2f(0, 0), sf::Color::Transparent, sf::Color(100, 100, 100), 1);
    int pos_x = arenaCell.cell.getPosition().x;
    int pos_y = arenaCell.cell.getPosition().y;

    for (int y = pos_y; y < pos_y + arenaCell.cell.getSize().y; y += 20) {
        for (int x = pos_x; x < pos_x + arenaCell.cell.getSize().x; x += 20) {
            cell.cell.setPosition(sf::Vector2f(x, y));
            window.draw(cell.cell);
        }
    }
    window.draw(arenaCell.cell);
}
