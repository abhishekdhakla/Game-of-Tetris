#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"
#include "board.h"

// sBlock implements blocks of type s
class sBlock: public Block{
    public:
    Board* gameBoard;
    sBlock(char, int, Board*, bool);
    sBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~sBlock(){}
};


#endif
