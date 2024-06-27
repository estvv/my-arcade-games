#ifndef MANAGE_BUBBLE_SHOOTER_HPP_
    #define MANAGE_BUBBLE_SHOOTER_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "colors.hpp"

class All;

class BubbleShooterGame {
    public:
        BubbleShooterGame(void);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void gameDisplay(sf::RenderWindow &window);
        void updateBreakoutColors(Colors colors);
        void initBreakout(void);

    private:
};

#endif /* !MANAGE_BUBBLE_SHOOTER_HPP_ */
