#include "music.hpp"
#include <iostream>

Music::Music(const std::string &filepath)
{
    if (not music.openFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
        exit(84);
    }
}
