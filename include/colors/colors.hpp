#ifndef COLORS_HPP_
    #define COLORS_HPP_
    #include "menu_colors.hpp"
    #include "breakout_colors.hpp"
    #include "snake_colors.hpp"
    #include "bubble_shooter_colors.hpp"
    #include "objects_colors.hpp"

class Colors {
    public:
        Colors(void);

        MenusColors menusColors;
        SnakeColors snakeColors;
        BreakoutColors breakoutColors;
        BubbleShooterColors bubbleShooterColors;
        ObjectsColors objectsColors;
    private:
};

#endif /* !COLORS_HPP_ */
