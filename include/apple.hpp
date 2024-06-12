#ifndef APPLE_HPP_
    #define APPLE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Apple {
    public:
        Apple(sf::Color appleColor);

        sf::RectangleShape apple;
    private:
};

#endif /* !APPLE_HPP_ */
