#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"
#include "board.h"

// oBlock implements blocks of type o
class oBlock: public Block{
    private:
    public:
    Board* gameBoard;
    oBlock(char, int ,Board*,bool);
    oBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~oBlock(){}
};


#endif
