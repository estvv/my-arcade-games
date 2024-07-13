#include "block.hpp"
#include "enum.hpp"
#include "arena.hpp"
#include "vector"
#include "iostream"

Block::Block(void)
{
}

void Block::createO_Block(void)
{
    blockPos[0] = sf::Vector2i(4, 0);
    blockPos[1] = sf::Vector2i(5, 0);
    blockPos[2] = sf::Vector2i(4, 1);
    blockPos[3] = sf::Vector2i(5, 1);
}

void Block::createI_Block(void)
{
    blockPos[0] = sf::Vector2i(4, 0);
    blockPos[1] = sf::Vector2i(4, 1);
    blockPos[2] = sf::Vector2i(4, 2);
    blockPos[3] = sf::Vector2i(4, 3);
}

void Block::createL_Block(void)
{
    blockPos[0] = sf::Vector2i(4, 0);
    blockPos[1] = sf::Vector2i(4, 1);
    blockPos[2] = sf::Vector2i(4, 2);
    blockPos[3] = sf::Vector2i(5, 2);
}

void Block::createJ_Block(void)
{
    blockPos[0] = sf::Vector2i(5, 0);
    blockPos[1] = sf::Vector2i(5, 1);
    blockPos[2] = sf::Vector2i(5, 2);
    blockPos[3] = sf::Vector2i(4, 2);
}

void Block::createZ_Block(void)
{
    blockPos[0] = sf::Vector2i(3, 0);
    blockPos[1] = sf::Vector2i(4, 0);
    blockPos[2] = sf::Vector2i(4, 1);
    blockPos[3] = sf::Vector2i(5, 1);
}

void Block::createS_Block(void)
{
    blockPos[0] = sf::Vector2i(3, 0);
    blockPos[1] = sf::Vector2i(4, 0);
    blockPos[2] = sf::Vector2i(4, 1);
    blockPos[3] = sf::Vector2i(5, 1);
}

void Block::createT_Block(void)
{
    blockPos[0] = sf::Vector2i(3, 0);
    blockPos[1] = sf::Vector2i(4, 0);
    blockPos[2] = sf::Vector2i(5, 0);
    blockPos[3] = sf::Vector2i(4, 1);
}

void Block::create_Block(vector<vector<blockType>> blocksArray)
{
    enum blockType randomizer = type;

    while (type == randomizer or type == NONE_block) {
        srand(time(NULL));
        type = (blockType)(rand() % 8);
    }
    is_stuck = false;
    switch (type) {
        case NONE_block:
            return;
        case O_block:
            createO_Block();
            break;
        case I_block:
            createI_Block();
            break;
        case J_block:
            createJ_Block();
            break;
        case L_block:
            createL_Block();
            break;
        case Z_block:
            createZ_Block();
            break;
        case S_block:
            createS_Block();
            break;
        case T_block:
            createT_Block();
            break;
    }
    for (sf::Vector2i pos : blockPos)
        blocksArray[pos.y][pos.x] = type;
}

