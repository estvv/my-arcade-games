#ifndef ARENA_HPP_
    #define ARENA_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "colors.hpp"

class Arena {
    public:
        Arena(sf::Vector2f size, sf::Vector2f pos);
        void initArena(sf::Vector2f size, sf::Vector2f pos);
        void drawArena(sf::RenderWindow &window);

        sf::RectangleShape arena;
    private:
};

#endif /* !ARENA_HPP_ */
