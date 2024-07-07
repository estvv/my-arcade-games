#include "settings.hpp"

Settings::Settings(void) :
    upInput(sf::Keyboard::Z),
    downInput(sf::Keyboard::S),
    leftInput(sf::Keyboard::Q),
    rightInput(sf::Keyboard::D),
    masterVolume(50),
    musicVolume(50),
    soundVolume(50)
{
}
