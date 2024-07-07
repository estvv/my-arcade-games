#include "sound.hpp"
#include <iostream>

using namespace std;

Sound::Sound(string filepath) :
    soundBuffer(make_shared<sf::SoundBuffer>())
{
    if (not soundBuffer->loadFromFile(filepath)) {
        cerr << "Problem with " + filepath + "." << endl;
        exit(84);
    }
    sound.setBuffer(*soundBuffer);
    sound.setVolume(50);
}
