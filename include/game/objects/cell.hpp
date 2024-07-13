#ifndef CELL_HPP_
    #define CELL_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class Cell {
    public:
        Cell(sf::Vector2f size, sf::Vector2f pos, sf::Color color, sf::Color outlineColor, float thickness);

        sf::RectangleShape cell;
    private:
};

#endif /* !CELL_HPP_ */
