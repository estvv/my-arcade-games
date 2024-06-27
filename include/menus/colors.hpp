#ifndef COLORS_HPP_
    #define COLORS_HPP_
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

class BreakoutColors {
    public:
        BreakoutColors(void);
    private:
};

class MenusColors {
    public:
        MenusColors(void);

        sf::Color mainColor;
        sf::Color button;
        sf::Color buttonText;
        sf::Color buttonHover;
        sf::Color buttonClicked;
    private:
};

class Colors {
    public:
        Colors(void);

        MenusColors menusColors;
        SnakeColors snakeColors;
        BreakoutColors breakoutColors;
    private:
};

#endif /* !COLORS_HPP_ */
