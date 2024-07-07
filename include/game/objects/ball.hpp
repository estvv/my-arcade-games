#ifndef BALL_HPP_
    #define BALL_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "colors.hpp"

class Ball {
    public:
        Ball(sf::Color color, sf::Vector2f position, float radius);

        sf::CircleShape shape;
    private:
};

#endif /* !BALL_HPP_ */
