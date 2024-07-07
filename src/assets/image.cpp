#include "image.hpp"
#include <iostream>

using namespace std;

Image::Image(const string &filepath, sf::Vector2f pos, sf::Vector2f scale) :
    texture(make_shared<sf::Texture>())
{
    if (not texture->loadFromFile(filepath)) {
        cerr << "Problem with " + filepath + "." << endl;
        exit(84);
    }
    sprite.setTexture(*texture);
    sprite.setPosition(pos);
    sprite.setScale(scale);
}

void Image::display(sf::RenderWindow &window)
{
    window.draw(sprite);
}
