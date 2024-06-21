#include "settings.hpp"

Settings::Settings(void) :
    up(sf::Keyboard::Z),
    down(sf::Keyboard::S),
    left(sf::Keyboard::Q),
    right(sf::Keyboard::D),
    masterVolume(50),
    musicVolume(50),
    soundVolume(50)
{
}
