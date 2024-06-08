#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include "snake.hpp"
    #include "apple.hpp"
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Game {
    public:
        Game(void);
        void run();
        void winDisplay();
        void manageEvent();
        void update();
        void endOfGame();
        void appelEating();
        void mooveSnake();

        Snake snake;
        Apple apple;
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock clock;
        sf::RectangleShape arena;
        sf::Font pixel_font;
        sf::Text score_txt;
        sf::Text round_txt;
        unsigned int score;
        unsigned int round;
    private:
};

#endif // EXAMPLE_HPP
