#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include "snake.hpp"
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

        Snake snake;
        sf::RenderWindow window;
        sf::Event event;
    private:
};

#endif // EXAMPLE_HPP
