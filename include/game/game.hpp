#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include "enum.hpp"
    #include "arena.hpp"
    #include "hud.hpp"
    #include "breakout_game.hpp"
    #include "snake_game.hpp"
    #include "bubble_shooter_game.hpp"
    #include "tetris_game.hpp"

class Game {
    public:
        Game(All *all, Colors colors, sf::RenderWindow &window);
        void gamesDisplay(void);
        void gamesUpdates(All &all);
        void gamesEvents(All &all);
        void updateGameColors(MenusColors menusColors);

        Hud hud;
        SnakeGame snakeGame;
        BreakoutGame breakoutGame;
        BubbleShooterGame bubbleShooterGame;
        TetrisGame tetrisGame;
        sf::RenderWindow &window;
        sf::Clock clock;
        unsigned int score = 0;
        unsigned int round = 1;
        enum game gameState;
    private:
};

#endif // EXAMPLE_HPP
