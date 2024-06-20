#include "image.hpp"
#include <iostream>

Image::Image(const std::string &filepath, sf::Vector2f pos, sf::Vector2f scale) :
    texture(std::make_shared<sf::Texture>())
{
    if (not texture->loadFromFile(filepath)) {
        std::cerr << "Problem with " + filepath + "." << std::endl;
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
