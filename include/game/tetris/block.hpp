#ifndef BLOCK_HPP_
    #define BLOCK_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

using namespace std;

enum blockType {
    NONE_block,
    I_block,
    J_block,
    L_block,
    O_block,
    S_block,
    Z_block,
    T_block
};

class Cell {
    public:
        Cell(void);

        sf::RectangleShape cell;
    private:
};

class Block {
    public:
        Block(void);

        enum blockType type;
        vector<Cell> block;
    private:
};

#endif /* !BLOCK_HPP_ */
