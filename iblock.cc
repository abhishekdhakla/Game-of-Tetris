#include "iblock.h"
#include "board.h"

iBlock::iBlock(char blockType, int level,Board* gameBoard, bool isHeavy):Block(blockType),gameBoard(gameBoard){
    this->level = level;
    orientationType = 0;
    posX = 0;
    posY = 3;
    // PIVOT is index (0,3)
    this->isHeavy = isHeavy;
    setCellBlock(0);
}

iBlock::iBlock(char blockType, int level,BlockCell cellCoords):Block(blockType){
    this->level = level;
    this->cellCoords->a = cellCoords.a;
    this->cellCoords->b = cellCoords.b;
    this->cellCoords->c = cellCoords.c;
    this->cellCoords->d = cellCoords.d;
}

void iBlock::setCellBlock(int targetOrientation){
    // this is normal block postion IIII
    if(targetOrientation==0 || targetOrientation==2){
        cellCoords->a.x = 0 + posX;
        cellCoords->a.y = 0 + posY;
        
        cellCoords->b.x = 1 + posX;
        cellCoords->b.y = 0 + posY;

        cellCoords->c.x = 2 + posX;
        cellCoords->c.y = 0 + posY;

        cellCoords->d.x = 3 + posX;
        cellCoords->d.y = 0 + posY;
    // I
    // I
    // I
    // I  block position
    } else if(targetOrientation==1 || targetOrientation==3){
        cellCoords->a.x = 0 + posX;
        cellCoords->a.y = -3 + posY;
        
        cellCoords->b.x = 0 + posX;
        cellCoords->b.y = -2 + posY;

        cellCoords->c.x = 0 + posX;
        cellCoords->c.y = -1 + posY;

        cellCoords->d.x = 0 + posX;
        cellCoords->d.y = 0 + posY;

    }
}

void iBlock::rotateCW(){
    BlockCell test;
    Cell a = {cellCoords->a.x, cellCoords->a.y};
    Cell b = {cellCoords->b.x, cellCoords->b.y};
    Cell c = {cellCoords->c.x, cellCoords->c.y};
    Cell d = {cellCoords->d.x, cellCoords->d.y};
    test = {a,b,c,d};
    int currOrr = this->orientationType;
    int targetOrr = currOrr+1;
    if(currOrr==3)  targetOrr = 0;
    this->setCellBlock(targetOrr);
    gameBoard->update(test, ' ');
    this->orientationType = targetOrr;
    if(!gameBoard->check(this->getCellCoords())){
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
        gameBoard->update(*cellCoords, 'I');
        this->orientationType = currOrr;
    }  else {
        gameBoard->update(*cellCoords, 'I');
    }
}
void iBlock::rotateCCW(){
    BlockCell test;
    Cell a = {cellCoords->a.x, cellCoords->a.y};
    Cell b = {cellCoords->b.x, cellCoords->b.y};
    Cell c = {cellCoords->c.x, cellCoords->c.y};
    Cell d = {cellCoords->d.x, cellCoords->d.y};
    test = {a,b,c,d};
    int currOrr = this->orientationType;
    int targetOrr = currOrr-1;
    if(currOrr==0)  targetOrr = 3;
    this->setCellBlock(targetOrr);
    gameBoard->update(test, ' ');
    this->orientationType = targetOrr;
    if(!gameBoard->check(this->getCellCoords())){
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
        gameBoard->update(*cellCoords, 'I');
        this->orientationType = currOrr;
    }  else {
        gameBoard->update(*cellCoords, 'I');
    }
}

void iBlock::left(){
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
        gameBoard->update(test,'I');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
        posX--;
    } else {
        gameBoard->update(*cellCoords,'I');
    }
}

void iBlock::down(){
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
        gameBoard->update(test,'I');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
        posY++;
    } else {
        gameBoard->update(*cellCoords,'I');
    }
}

void iBlock::right(){
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
        gameBoard->update(test,'I');
        cellCoords->a = test.a;
        cellCoords->b = test.b;
        cellCoords->c = test.c;
        cellCoords->d = test.d;
        posX++;
    } else {
        gameBoard->update(*cellCoords,'I');
    }
}

void iBlock::drop(){
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
        gameBoard->update(*cellCoords,'I');
    } else {
        gameBoard->update(*cellCoords,'I');
    }
}

char iBlock::getBlockType(){
	return 'I';
}
