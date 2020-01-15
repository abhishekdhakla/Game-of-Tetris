#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"
#include "board.h"
#include "blockCell.h"

// jBlock implements blocks of type j
class jBlock: public Block{
    private:
    public:
    Board* gameBoard;
    void  setCellBlock(int) override;
    jBlock(char, int, Board*,bool);
    jBlock(char,int,BlockCell);
    // Action items for Blocks
    void rotateCW() override;
    void rotateCCW() override;
    void left() override;
    void down() override;
    void right() override;
    void drop() override;
    char getBlockType() override;
    ~jBlock(){}

};


#endif
