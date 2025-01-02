#ifndef BLOCKS_HPP_
    #define BLOCKS_HPP_
    #include "block.hpp"

class Blocks {
    public:
        Blocks(void);
        void initBlocksArray(void);
        void displayBlocksArray(sf::RenderWindow &window);
        bool blockCanMoove(const int x, const int y);
        void updateBlockRotation(void);
        bool updatePosition(const int x, const int y);
        void checkCompleteLine(void);
        void destroyBlocksLine(int y);

        Block block;
        vector<vector<blockType>> blocksArray;
    private:
};

#endif /* !BLOCKS_HPP_ */
