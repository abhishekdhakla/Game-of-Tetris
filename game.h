#ifndef GAME_H
#define GAME_H


#include "block.h"
#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "score.h"
#include "graphicsDisplay.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

class Game{
    Board gameBoard;
    int level;
    int highScore;
    bool restartGame;
    int cur;
    bool textOnly;
    string input;
    ifstream file;
    Score score;
    int l4counter;
    int randSeed;
    vector<char> sequenceInput;
    vector<char> noRandomSequence;
    bool noRandom;
    int noRandomIndex;
    shared_ptr<Block> currentBlock = nullptr;
    shared_ptr<Block> nextBlock = nullptr;
    GraphicsDisplay graphic;
    bool isHeavy;
    bool hint;
    int hintRow;

    public:
    // constructor
    Game(int level, string input, bool textOnly,int randSeed);
    // run the game using play
    void play();
    // generate the next block
    shared_ptr<Block> generateBlock(bool);
    char selectBlock();
    ~Game();
    void command(string);
    void printNext();
    void printGameData();
    shared_ptr<Block> createUniqueCopyBlock(shared_ptr<Block>);
};

#endif
