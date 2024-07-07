#ifndef MANAGE_SNAKE_HPP_
    #define MANAGE_SNAKE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "snake.hpp"
    #include "apple.hpp"
    #include "arena.hpp"
    #include "colors.hpp"
    #include "hud.hpp"

class All;

class SnakeGame {
    public:
        SnakeGame(SnakeColors snakeColors);
        void initSnake(void);
        void updateSnakeColors(Colors colors);
        void gameDisplay(sf::RenderWindow &window);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void endOfGame(All &all);
        void appelEating(All &all);
        void mooveSnake(All &all);

        Arena arena;
        Snake snake;
        Apple apple;
    private:
};

#endif /* !MANAGE_SNAKE_HPP_ */
