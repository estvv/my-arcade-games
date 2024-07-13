#include "apple.hpp"
#include "cell.hpp"

Apple::Apple(Arena arena, sf::Color appleColor) :
    appleCell(sf::Vector2f(20, 20), sf::Vector2f(0, 0), appleColor, sf::Color::Transparent, 0)
{
    putAppleToRandomPlace(arena);
}

void Apple::putAppleToRandomPlace(Arena arena)
{
    sf::Vector2i size(arena.arenaCell.cell.getSize().x, arena.arenaCell.cell.getSize().y);
    sf::Vector2i pos(arena.arenaCell.cell.getPosition().x, arena.arenaCell.cell.getPosition().y);

    srand(time(NULL));
    appleCell.cell.setPosition(20 * (rand() % (size.x / 20)) + pos.x, 20 * (rand() % (size.y / 20)) + pos.y);
}
