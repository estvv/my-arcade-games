#ifndef MANAGE_BREAKOUT_HPP_
    #define MANAGE_BREAKOUT_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "colors.hpp"
    #include "brick.hpp"

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

        vector<vector<Brick>> targetBricks;
    private:
};

#endif /* !MANAGE_BREAKOUT_HPP_ */
