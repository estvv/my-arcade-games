#include "music.hpp"
#include "all.hpp"
#include <iostream>

Music::Music(const std::string &filepath) :
    music(std::make_shared<sf::Music>())
{
    if (not music->openFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
        exit(84);
    }
}
