#include "apple.hpp"

Apple::Apple(void) : apple(sf::Vector2f(20, 20))
{
    apple.setFillColor(sf::Color::Red);
    srand(time(NULL));
    apple.setPosition(20 * (rand() % 38) + 40, 20 * (rand() % 38) + 40);
}
