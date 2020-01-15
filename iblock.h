#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"
#include "board.h"

// iBlock implements blocks of type i
class iBlock: public Block{
    public:
    Board* gameBoard;
    iBlock(char, int ,Board*,bool);
    iBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~iBlock(){}
};


#endif
