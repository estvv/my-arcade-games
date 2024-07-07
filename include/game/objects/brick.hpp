#ifndef BRICK_HPP_
    #define BRICK_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Brick {
    public:
        Brick(sf::Color color, sf::Vector2f position, sf::Vector2f size);

        sf::RectangleShape shape;
    private:
};

#endif /* !BRICK_HPP_ */
