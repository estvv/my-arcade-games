#ifndef BLOCK_HPP_
    #define BLOCK_HPP_
    #include "cell.hpp"

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

class Arena;

class Block {
    public:
        Block(void);
        void createO_Block(void);
        void createI_Block(void);
        void createZ_Block(void);
        void createS_Block(void);
        void createL_Block(void);
        void createJ_Block(void);
        void createT_Block(void);
        void create_Block(vector<vector<blockType>> blockArray);

        enum blockType type = NONE_block;
        bool is_stuck = false;
        sf::Vector2i blockPos[4];
    private:
};

#endif /* !BLOCK_HPP_ */
