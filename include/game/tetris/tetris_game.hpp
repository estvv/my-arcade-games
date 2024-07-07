#ifndef TETRIS_GAME_HPP_
    #define TETRIS_GAME_HPP_
    #include "colors.hpp"
    #include "block.hpp"
    #include "arena.hpp"

class All;

class TetrisGame {
    public:
        TetrisGame(void);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void gameDisplay(sf::RenderWindow &window);
        void updateTetrisColors(Colors colors);
        void initTetris(void);

        Arena arena;
    private:
};

#endif /* !TETRIS_GAME_HPP_ */
