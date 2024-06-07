#include "game.hpp"
#include "snake.hpp"

int main(int ac, char **av)
{
    Game game;

    if (ac != 1)
        return 84;
    game.run();
    return 0;
}
