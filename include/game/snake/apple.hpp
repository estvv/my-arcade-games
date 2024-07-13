#ifndef APPLE_HPP_
    #define APPLE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "arena.hpp"
    #include "cell.hpp"

class Apple {
    public:
        Apple(Arena arena, sf::Color appleColor);
        void putAppleToRandomPlace(Arena arena);

        Cell appleCell;
    private:
};

#endif /* !APPLE_HPP_ */
