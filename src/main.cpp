#include "all.hpp"

int main(int ac, char **av)
{
    All all;

    if (ac != 1)
        return 84;
    all.loop();
    return 0;
}
