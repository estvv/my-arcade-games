#include "block.hpp"

Cell::Cell(void)
{
    //cell.setSize();
    cell.setFillColor(sf::Color::Red);
}

Block::Block(void) :
    type(NONE_block)
{
    block.push_back(Cell());
}
