#include "music.hpp"
#include "all.hpp"
#include <iostream>

using namespace std;

Music::Music(const string &filepath) :
    music(make_shared<sf::Music>())
{
    if (not music->openFromFile(filepath)) {
        cerr << "Problem with " + filepath + "." << endl;
        exit(84);
    }
}
