#ifndef TETRIS_GAME_HPP_
    #define TETRIS_GAME_HPP_
    #include <vector>
    #include "colors.hpp"
    #include "block.hpp"
    #include "blocks.hpp"
    #include "arena.hpp"

class All;

class TetrisGame {
    enum pauseState {
        ON,
        OFF
    };
    public:
        TetrisGame(void);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void gameDisplay(sf::RenderWindow &window);
        void updateTetrisColors(Colors colors);
        void initTetris(void);

        pauseState onPause = OFF;
        Arena arena;
        Blocks blocks;
    private:
};

#endif /* !TETRIS_GAME_HPP_ */
