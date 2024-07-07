#include "font.hpp"
#include <iostream>

using namespace std;

Font::Font(string filepath)
{
    if (not font.loadFromFile(filepath)) {
        cerr << "Problem with " + filepath + "." << endl;
        exit(84);
    }
}
