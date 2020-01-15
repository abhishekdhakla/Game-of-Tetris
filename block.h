#ifndef BLOCK_H
#define BLOCK_H

#include "cell.h"
#include "blockCell.h"
#include <vector>
#include <memory>

using namespace std;

// Block is the concrete class that implements structure for Block element in Tetris
class Block{
    protected:
    int posX;
    int posY;
    int level; // stores the level with which block was created
    int orientationType; // orientationType = {0,1,2,3} depending on rotations by 90 deg
    char blockType;
    shared_ptr<BlockCell> cellCoords;
    virtual void setCellBlock(int) = 0;
    public:
    bool isHeavy;
    Block(char blockType);
    virtual ~Block();
    
    // getters
    // int getOrientation(); // returns {0,1,2,3} depending on current orientation
    int getLevel(); //  returns level of current block
    int getPosX(); //  returns X position of block
    int getPosY(); //  returns Y position of block
    BlockCell& getCellCoords();
    void setCellCoords(BlockCell&);

    // setters
    // void setOrientation(int); // sets the rotation orientation for the block

    // Action items for Blocks
    // void increaseLevel();
    // void decreaseLevel();

    virtual void rotateCW() = 0;
    virtual void rotateCCW() = 0;
    virtual void left() = 0;
    virtual void down() = 0;
    virtual void right()= 0;
    virtual void drop() = 0;
    virtual char getBlockType()= 0;

};


#endif
