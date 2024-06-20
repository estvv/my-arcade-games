#include "sound.hpp"
#include <iostream>

Sound::Sound(std::string filepath) :
    soundBuffer(std::make_shared<sf::SoundBuffer>())
{
    if (not soundBuffer->loadFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
        exit(84);
    }
    sound.setBuffer(*soundBuffer);
    sound.setVolume(50);
}
