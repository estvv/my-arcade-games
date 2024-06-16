#ifndef COLORS_HPP_
    #define COLORS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Colors {
    public:
        Colors(void);

        sf::Color mainColor;
        sf::Color button;
        sf::Color buttonText;
        sf::Color buttonHover;
        sf::Color buttonClicked;
        sf::Color snakeHead;
        sf::Color snakeBody;
        sf::Color apple;
    private:
};

#endif /* !COLORS_HPP_ */
