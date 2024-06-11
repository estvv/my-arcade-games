#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include "snake.hpp"
    #include "apple.hpp"
    #include "enum.hpp"
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Game {
    public:
        Game(sf::RenderWindow &window);
        void displayGame();
        void manageGameEvent(sf::Event event, enum screens &screen_id);
        void update();
        void endOfGame();
        void appelEating();
        void mooveSnake();

        Snake snake;
        Apple apple;
        sf::RenderWindow &window;
        sf::Clock clock;
        sf::RectangleShape arena;
        sf::Font font;
        sf::Text score_txt;
        sf::Text round_txt;
        unsigned int score;
        unsigned int round;
    private:
};

#endif // EXAMPLE_HPP
