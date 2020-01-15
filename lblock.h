#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"
#include "board.h"

// lBlock implements blocks of type l
class lBlock: public Block{
    private:
    public:
    Board* gameBoard;
    lBlock(char,int ,Board*, bool);
    lBlock(char,int,BlockCell);
    void setCellBlock(int) override;
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~lBlock(){}
};


#endif
