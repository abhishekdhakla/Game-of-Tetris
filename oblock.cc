#include "oblock.h"
#include "board.h"

oBlock::oBlock(char blockType, int level,Board* gameBoard , bool isHeavy):Block(blockType),gameBoard(gameBoard){
    this->level = level;
    orientationType = 0;
    posX = 0;
    posY = 3;
    setCellBlock(0);
    this->isHeavy = isHeavy;
}

oBlock::oBlock(char blockType, int level,BlockCell cellCoords):Block(blockType){
    this->level = level;
    this->cellCoords->a = cellCoords.a;
    this->cellCoords->b = cellCoords.b;
    this->cellCoords->c = cellCoords.c;
    this->cellCoords->d = cellCoords.d;
}

void oBlock::setCellBlock(int targetOrientation){
    cellCoords->a.x = 0 + posX;
    cellCoords->a.y = 0 + posY;
        
    cellCoords->b.x = 1 + posX;
    cellCoords->b.y = 0 + posY;

    cellCoords->c.x = 0 + posX;
    cellCoords->c.y = -1 + posY;

    cellCoords->d.x = 1 + posX;
    cellCoords->d.y = -1 + posY;
}

void oBlock::rotateCW(){}
void oBlock::rotateCCW(){}
void oBlock::left(){
    // Create coordinates for potentially new block
    BlockCell test;
    Cell a = {cellCoords->a.x-1, cellCoords->a.y};
    Cell b = {cellCoords->b.x-1, cellCoords->b.y};
    Cell c = {cellCoords->c.x-1, cellCoords->c.y};
    Cell d = {cellCoords->d.x-1, cellCoords->d.y};
    test = {a,b,c,d};
    // set current coordinates to be ' ', if check fails, revert back
    gameBoard->update(*cellCoords, ' ');
    if(gameBoard->check(test)){
        gameBoard->update(test,'O');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
    } else {
        gameBoard->update(*cellCoords,'O');
    }
}
void oBlock::down(){
        // Create coordinates for potentially new block
    BlockCell test;
    Cell a = {cellCoords->a.x, cellCoords->a.y+1};
    Cell b = {cellCoords->b.x, cellCoords->b.y+1};
    Cell c = {cellCoords->c.x, cellCoords->c.y+1};
    Cell d = {cellCoords->d.x, cellCoords->d.y+1};
    test = {a,b,c,d};
    // set current coordinates to be ' ', if check fails, revert back
    gameBoard->update(*cellCoords, ' ');
    if(gameBoard->check(test)){
        gameBoard->update(test,'O');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
    } else {
        gameBoard->update(*cellCoords,'O');
    }
}
void oBlock::right(){
    // Create coordinates for potentially new block
    BlockCell test;
    Cell a = {cellCoords->a.x+1, cellCoords->a.y};
    Cell b = {cellCoords->b.x+1, cellCoords->b.y};
    Cell c = {cellCoords->c.x+1, cellCoords->c.y};
    Cell d = {cellCoords->d.x+1, cellCoords->d.y};
    test = {a,b,c,d};
    // set current coordinates to be ' ', if check fails, revert back
    gameBoard->update(*cellCoords, ' ');
    if(gameBoard->check(test)){
        gameBoard->update(test,'O');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
    } else {
        gameBoard->update(*cellCoords,'O');
    }
}
void oBlock::drop(){
        // do repeated downs until necessary!
    BlockCell test;
    Cell a = {cellCoords->a.x, cellCoords->a.y+1};
    Cell b = {cellCoords->b.x, cellCoords->b.y+1};
    Cell c = {cellCoords->c.x, cellCoords->c.y+1};
    Cell d = {cellCoords->d.x, cellCoords->d.y+1};
    test = {a,b,c,d};
    // set current coordinates to be ' ', if check fails, revert back
    gameBoard->update(*cellCoords, ' ');
    if(gameBoard->check(test)){
        while(gameBoard->check(test)) {
            // do repeated downs until necessary
            down();
            a = {cellCoords->a.x, cellCoords->a.y+1};
            b = {cellCoords->b.x, cellCoords->b.y+1};
            c = {cellCoords->c.x, cellCoords->c.y+1};
            d = {cellCoords->d.x, cellCoords->d.y+1};
            test = {a,b,c,d};
            gameBoard->update(*cellCoords,' ');
        }
        gameBoard->update(*cellCoords,'O');
    } else {
        gameBoard->update(*cellCoords,'O');
    }
}
char oBlock::getBlockType(){
	return 'O';
}
