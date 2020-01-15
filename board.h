#ifndef BOARD_H
#define BOARD_H

#define MAXHEIGHT = 18
#define MAXWIDTH = 11

#include "blockCell.h"
#include "block.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

// Board is the concrete class that implements structure for Board element in Tetris
class Board{
    int height=18;
    int width=11;
    int level=0;
    int starBonus=0;
    vector<vector<char> > gameBoard;
    // vector<vector<char>>(MAXHEIGHT,vector<char>(MAXWIDTH, ' '));
    public:
    vector<shared_ptr<Block> >boardBlocks;
    friend std::ostream& operator<<(std::ostream &out, const Board &currBoard);
    Board(int height=18,int width=11);
    bool isRowFull(int);
    bool isEmptyRow(int);
    int getHeight();
    int getWidth();
    int clearRow();
    int addHint(char, char);
    void removeHint(int);
    void clear();
    int getStarBonus();
    ~Board();
    bool check(BlockCell&);
    char getCell(int,int);
    vector<vector<char> >& getBoard();
    void update(BlockCell&, char);
    int checkDeadBlocks();
};


#endif
