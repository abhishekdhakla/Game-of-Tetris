#include <iostream>
#include "block.h"
#include "blockCell.h"

using namespace std;

// Constructor for setting cellCoordinates to 0
Block::Block(char blockType){
    cellCoords = make_shared<BlockCell>();
    this->blockType = blockType;
    cellCoords->a.x=0;
    cellCoords->a.y=0;

    cellCoords->b.x=0;
    cellCoords->b.y=0;

    cellCoords->c.x=0;
    cellCoords->c.y=0;

    cellCoords->d.x=0;
    cellCoords->d.y=0;
}

// Destructor

Block::~Block(){}


// gets Position X
int Block::getPosX(){
    return posX;
}

// gets Position Y
int Block::getPosY(){
    return posY;
}


int Block::getLevel(){
    return level;
}

BlockCell& Block::getCellCoords(){
    return *cellCoords;
}
void Block::setCellCoords(BlockCell& newState){
    cellCoords->a =newState.a;
    cellCoords->b =newState.b;
    cellCoords->c =newState.c;
    cellCoords->d =newState.d;
}


