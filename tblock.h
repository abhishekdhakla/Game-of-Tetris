#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"
#include "board.h"

// tBlock implements blocks of type t
class tBlock: public Block{
    public:
    Board* gameBoard;
    tBlock(char, int ,Board*, bool);
    tBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~tBlock(){}
};


#endif
