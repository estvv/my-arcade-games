#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include "enum.hpp"
    #include "manage_breakout.hpp"
    #include "manage_snake.hpp"

class Game {
    public:
        Game(All *all, Colors colors, sf::RenderWindow &window);
        void gamesDisplay(void);
        void gamesUpdates(All &all);
        void gamesEvents(All &all);
        void updateGameColors(MenusColors menusColors);

        SnakeGame snakeGame;
        BreakoutGame breakoutGame;
        sf::RenderWindow &window;
        sf::Clock clock;
        sf::RectangleShape arena;
        sf::Text scoreText;
        sf::Text roundText;
        unsigned int score;
        unsigned int round;
        enum game gameState;
    private:
};

#endif // EXAMPLE_HPP
