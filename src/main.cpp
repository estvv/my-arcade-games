#include "all.hpp"

int main(int ac, UN char **av)
{
    All all;

    if (ac != 1)
        return 84;
    all.gameLoop();
    return 0;
}
