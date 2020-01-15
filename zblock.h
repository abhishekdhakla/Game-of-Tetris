#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"
#include "board.h"

// zBlock implements blocks of type z
class zBlock: public Block{
    public:
    Board* gameBoard;
    zBlock(char, int, Board*,bool);
    zBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~zBlock(){}

};


#endif
