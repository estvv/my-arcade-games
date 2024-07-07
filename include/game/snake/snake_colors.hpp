#ifndef SNAKE_COLORS_HPP_
    #define SNAKE_COLORS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class SnakeColors {
    public:
        SnakeColors(void);

        sf::Color snakeHead;
        sf::Color snakeBody;
        sf::Color apple;
    private:
};

#endif /* !SNAKE_COLORS_HPP_ */
