#include "blocks.hpp"
#include "enum.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Blocks::Blocks(void)
{
    initBlocksArray();
    block.create_Block(blocksArray);
}

// Init the arena's array with empty Cells
void Blocks::initBlocksArray(void)
{
    vector<blockType> row;

    blocksArray.clear();
    for (int i = 0; i < 25; i++) {
        row.clear();
        for (int j = 0; j < 10; j++)
            row.emplace_back(NONE_block);
        blocksArray.push_back(row);
    }
}

bool Blocks::blockCanMoove(const int x, const int y)
{
    for (sf::Vector2i pos : block.blockPos)
        blocksArray[pos.y][pos.x] = NONE_block;
    for (int i = 0; i < 4; i++) {
        if (block.blockPos[i].x + x < 0 or block.blockPos[i].x + x >= 10 or block.blockPos[i].y + y < 0) {
            std::cerr << "Can't move from (" + to_string(block.blockPos[i].x) + "," + to_string(block.blockPos[i].y) + ") to (" + to_string(block.blockPos[i].x + x) + "," + to_string(block.blockPos[i].y + y) + ")" << std::endl;
            return false;
        }
        if (block.blockPos[i].y + y >= 24 or blocksArray[block.blockPos[i].y + y][block.blockPos[i].x + x] != NONE_block) {
            std::cerr << "Next is a block." << std::endl;
            block.is_stuck = true;
            return false;
        }
    }
    return true;
}

bool Blocks::updatePosition(const int x, const int y)
{
    if (!blockCanMoove(x, y)) {
        for (sf::Vector2i pos : block.blockPos)
            blocksArray[pos.y][pos.x] = block.type;
        return false;
    }
    std::cout << "move !" << std::endl;
    for (sf::Vector2i pos : block.blockPos)
        blocksArray[pos.y][pos.x] = NONE_block;
    for (sf::Vector2i &pos : block.blockPos) {
        pos.x += x;
        pos.y += y;
        blocksArray[pos.y][pos.x] = block.type;
    }
    return true;
}

void Blocks::updateBlockRotation(void)
{
    sf::Vector2i center(block.blockPos[3]);
    sf::Vector2i new_pos;

    if (block.type == O_block)
        return;
    if (block.type == T_block or block.type == L_block or block.type == J_block)
        center = block.blockPos[1];
    else if (block.type == S_block or block.type == Z_block or block.type == I_block)
        center = block.blockPos[2];

    for (sf::Vector2i pos : block.blockPos)
        blocksArray[pos.y][pos.x] = NONE_block;
    for (sf::Vector2i &pos : block.blockPos) {
        new_pos = sf::Vector2i(-(pos.y - center.y) + center.x, (pos.x - center.x) + center.y);
        pos.x = new_pos.x;
        pos.y = new_pos.y;
        blocksArray[pos.y][pos.x] = block.type;
    }
}

void Blocks::displayBlocksArray(sf::RenderWindow &window)
{
    sf::Vector2f pos(300, 260);
    static sf::RectangleShape shape(sf::Vector2f(20, 20));
    static sf::Color colors[] = {sf::Color::Transparent, sf::Color::Yellow, sf::Color::Cyan, sf::Color(255, 128, 0), sf::Color::Blue, sf::Color::Red, sf::Color::Green, sf::Color::Magenta};

    for (vector<blockType> y : blocksArray) {
        for (blockType x : y) {
            shape.setFillColor(colors[x]);
            shape.setPosition(pos);
            window.draw(shape);
            pos.x += 20;
        }
        pos.x = 300;
        pos.y += 20;
    }
}
