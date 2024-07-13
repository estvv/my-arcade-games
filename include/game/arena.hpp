#ifndef ARENA_HPP_
    #define ARENA_HPP_
    #include "colors.hpp"
    #include "cell.hpp"
class Arena {
    public:
        Arena(sf::Vector2f size, sf::Vector2f pos);
        void drawArena(sf::RenderWindow &window);

        Cell arenaCell;
    private:
};

#endif /* !ARENA_HPP_ */
