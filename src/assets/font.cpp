#include "font.hpp"
#include <iostream>

Font::Font(std::string filepath)
{
    if (not font.loadFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
        exit(84);
    }
}
