#ifndef MANAGE_BREAKOUT_HPP_
    #define MANAGE_BREAKOUT_HPP_
    #include "colors.hpp"
    #include "cell.hpp"

using namespace std;

class All;

class BreakoutGame {
    public:
        BreakoutGame(void);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void gameDisplay(sf::RenderWindow &window);
        void updateBreakoutColors(Colors colors);
        void initBreakout(void);

        vector<vector<Cell>> targetBricks;
    private:
};

#endif /* !MANAGE_BREAKOUT_HPP_ */
