#ifndef MANAGE_BUBBLE_SHOOTER_HPP_
    #define MANAGE_BUBBLE_SHOOTER_HPP_
    #include "colors.hpp"
    #include "ball.hpp"

using namespace std;

class All;

class BubbleShooterGame {
    public:
        BubbleShooterGame(ObjectsColors colors);
        void gameEvent(All &all);
        void gameUpdate(All &all);
        void gameDisplay(sf::RenderWindow &window);
        void updateBubbleShooterColors(ObjectsColors colors);
        void initBubbleShooter(void);
        void initTargetBalls(ObjectsColors colors);

        Ball shootingBall;
        vector<vector<Ball>> targetsBalls;
    private:
};

#endif /* !MANAGE_BUBBLE_SHOOTER_HPP_ */
