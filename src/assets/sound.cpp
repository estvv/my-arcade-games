#include "sound.hpp"
#include <iostream>

Sound::Sound(std::string filepath)
{
    if (not soundBuffer.loadFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
        exit(84);
    }
    sound.setBuffer(soundBuffer);
}
