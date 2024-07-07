#include "apple.hpp"

Apple::Apple(Arena arena, sf::Color appleColor) : apple(sf::Vector2f(20, 20))
{
    apple.setFillColor(appleColor);
    putAppleToRandomPlace(arena);
}

void Apple::putAppleToRandomPlace(Arena arena)
{
    sf::Vector2i size(arena.arena.getSize().x, arena.arena.getSize().y);
    sf::Vector2i pos(arena.arena.getPosition().x, arena.arena.getPosition().y);

    srand(time(NULL));
    apple.setPosition(20 * (rand() % (size.x / 20)) + pos.x, 20 * (rand() % (size.y / 20)) + pos.y);
}
