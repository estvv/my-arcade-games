#include "apple.hpp"
#include "colors.hpp"

Apple::Apple(sf::Color appleColor) : apple(sf::Vector2f(20, 20))
{
    apple.setFillColor(appleColor);
    srand(time(NULL));
    apple.setPosition(20 * (rand() % 38) + 40, 20 * (rand() % 38) + 40);
}
