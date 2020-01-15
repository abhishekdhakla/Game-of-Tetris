#include "game.h"
#include "block.h"
#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "blockCell.h"
#include <memory>
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

// constructor
Game::Game(int level, string input,bool textOnly, int randSeed):level(level), input(input),textOnly(textOnly),randSeed(randSeed){
    file.open(input);
    if(!file){
        cout << "sequence.txt or file passed from command line not found!";
    } else {
        char i;
        while(file >> i){
        sequenceInput.push_back(i);
        }
    }
    cur = 0;
    highScore = 0;
    restartGame=false;
    isHeavy=false;
    if(level>=3) isHeavy = true;
    noRandom=false;
    noRandomIndex=0;
    l4counter=0;
    if(level==4){
        l4counter=5;
    }
    hint = false;
    hintRow = 0;
}

char Game::selectBlock(){
    char blockType;
    if(level == 0){
        if(cur >= sequenceInput.size()){
            blockType = 'N';
            return blockType;
        }
        char i = sequenceInput[cur];
        if(i == 'I'){
            blockType = 'I';
        }
        else if(i == 'J'){
            blockType = 'J';
        }
        else if(i == 'L'){
            blockType = 'L';
        }
        else if(i == 'O'){
            blockType = 'O';
        }
        else if(i == 'S'){
            blockType = 'S';
        }
        else if(i == 'Z'){
            blockType = 'Z';
        }
        else if(i == 'T'){
            blockType = 'T';
        } else{
            blockType = 'N';
        }
        cur++;
    } else if(level == 1){
        int generateIndex = rand() % 12;
        if(generateIndex == 0){
            blockType = 'S';
        } else if(generateIndex == 1){
            blockType = 'Z';
        } else if(generateIndex == 2 || generateIndex == 3){
            blockType = 'I';
        } else if(generateIndex == 4 || generateIndex == 5){
            blockType = 'J';
        } else if(generateIndex == 6 || generateIndex == 7){
            blockType = 'T';
        }  else if(generateIndex == 8 || generateIndex == 9){
            blockType = 'L';
        } else if(generateIndex == 10 || generateIndex == 11){
            blockType = 'O';
        }
    } else if(level == 2){
        int generateIndex = rand() % 7;
        if(generateIndex == 0){
            blockType = 'S';
        } else if(generateIndex == 1){
            blockType = 'Z';
        } else if(generateIndex == 2){
            blockType = 'I';
        } else if(generateIndex == 3){
            blockType = 'J';
        } else if(generateIndex == 4){
            blockType = 'T';
        }  else if(generateIndex == 5){
            blockType = 'L';
        } else if(generateIndex == 6){
            blockType = 'O';
        }
    } else if(level == 3){
        if(noRandom){
            if(noRandomIndex >= noRandomSequence.size()){
                blockType = 'N';
                return blockType;
            }
            char i = noRandomSequence[noRandomIndex];
            if(i == 'I'){
                blockType = 'I';
            }
            else if(i == 'J'){
                blockType = 'J';
            }
            else if(i == 'L'){
                blockType = 'L';
            }
            else if(i == 'O'){
                blockType = 'O';
            }
            else if(i == 'S'){
                blockType = 'S';
            }
            else if(i == 'Z'){
                blockType = 'Z';
            }
            else if(i == 'T'){
                blockType = 'T';
            } else{
                blockType = 'N';
            }
            noRandomIndex++;
        } else {
            int generateIndex = rand() % 9;
            if(generateIndex == 0 || generateIndex ==1){
                blockType = 'S';
            } else if(generateIndex == 2 || generateIndex == 3){
                blockType = 'Z';
            } else if(generateIndex == 4){
                blockType = 'I';
            } else if(generateIndex == 5){
                blockType = 'J';
            } else if(generateIndex == 6){
                blockType = 'T';
            }  else if(generateIndex == 7){
                blockType = 'L';
            } else if(generateIndex == 8){
                blockType = 'O';
            }
        }
    } else if(level == 4){
        if(noRandom){
            if(noRandomIndex >= noRandomSequence.size()){
                blockType = 'N';
                return blockType;
            }
            char i = noRandomSequence[noRandomIndex];
            if(i == 'I'){
                blockType = 'I';
            }
            else if(i == 'J'){
                blockType = 'J';
            }
            else if(i == 'L'){
                blockType = 'L';
            }
            else if(i == 'O'){
                blockType = 'O';
            }
            else if(i == 'S'){
                blockType = 'S';
            }
            else if(i == 'Z'){
                blockType = 'Z';
            }
            else if(i == 'T'){
                blockType = 'T';
            } else{
                blockType = 'N';
            }
            noRandomIndex++;
        } else {
            int generateIndex = rand() % 9;
            if(generateIndex == 0 || generateIndex ==1){
                blockType = 'S';
            } else if(generateIndex == 2 || generateIndex == 3){
                blockType = 'Z';
            } else if(generateIndex == 4){
                blockType = 'I';
            } else if(generateIndex == 5){
                blockType = 'J';
            } else if(generateIndex == 6){
                blockType = 'T';
            }  else if(generateIndex == 7){
                blockType = 'L';
            } else if(generateIndex == 8){
                blockType = 'O';
            }
        }
    }
    return blockType;
}

//Assign nextBlock to currentBlock before calling this function
shared_ptr<Block> Game::generateBlock(bool isHeavy){
    char blockType = selectBlock();
    shared_ptr<Block> newBlock = nullptr;
    if(blockType == 'I'){
        newBlock = make_shared<iBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'J'){
        newBlock = make_shared<jBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'L'){
        newBlock = make_shared<lBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'O'){
        newBlock = make_shared<oBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'S'){
        newBlock = make_shared<sBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'Z'){
        newBlock = make_shared<zBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'T'){
        newBlock = make_shared<tBlock>(blockType, level, &gameBoard, isHeavy);
    }
    else if(blockType == 'N'){
        return nullptr;
    }
    return newBlock;
}

Game::~Game(){
    file.close();
}

void Game::command(string cmd){
    int multiplier=1;
    if(cmd.length()>=2){
        // max multiply for us should be <=18 so just check first two chars for multiplier;
        if(int(cmd[0])>=48 && int(cmd[0])<=57){
            multiplier = cmd[0] - '0';
            cmd = cmd.substr(1,string::npos);
            if(int(cmd[0])>=48 && int(cmd[0])<=57){
                multiplier = multiplier*10 + (cmd[0] - '0');
                cmd = cmd.substr(1,string::npos);
            }
        }
    }
    if(cmd == "lef" || cmd == "left"){
        while(multiplier!=0){
            currentBlock->left();
            multiplier--;
        }
        if(currentBlock->isHeavy){
            currentBlock->down();
        }
    }
    else if(cmd == "ri"  || cmd == "rig"  || cmd == "righ"  || cmd == "right"){
        while(multiplier!=0){
            currentBlock->right();
            multiplier--;
        }
        if(currentBlock->isHeavy){
            currentBlock->down();
        }
    }
    else if(cmd == "do" || cmd == "dow" || cmd == "down"){
        while(multiplier!=0){
            currentBlock->down();
            multiplier--;
        }
        if(currentBlock->isHeavy){
            currentBlock->down();
        }
    }
    else if(cmd == "cl" || cmd == "clo" || cmd == "cloc" || cmd == "clock" || cmd == "clockw" || cmd == "clockwi" || cmd == "clockwis" || cmd == "clockwise"){
        while(multiplier!=0){
            currentBlock->rotateCW();
            multiplier--;
        }
        if(currentBlock->isHeavy){
            currentBlock->down();
        }
    }
    else if(cmd == "co" || cmd == "cou" || cmd == "coun" || cmd == "count" || cmd == "counte" || cmd == "counter"
    || cmd == "counterc" || cmd == "countercl" || cmd == "counterclo" || cmd == "countercloc"
    || cmd == "counterclock" || cmd == "counterclockw" || cmd == "counterclockwi" || cmd == "counterclockwis" || cmd == "counterclockwise"){
        while(multiplier!=0){
            currentBlock->rotateCCW();
            multiplier--;
        }
        if(currentBlock->isHeavy){
            currentBlock->down();
        }
    }
    else if(cmd == "dr" || cmd == "dro" || cmd == "drop"){
        while(multiplier!=0){
            if(level==4) l4counter--;
            currentBlock->drop();
            gameBoard.boardBlocks.push_back(createUniqueCopyBlock(currentBlock));
            int lines = gameBoard.clearRow();
            int checkDeadBlockScore = 0;
            int bonus = 0;
            if(lines > 0) {
                checkDeadBlockScore = gameBoard.checkDeadBlocks();
                bonus = gameBoard.getStarBonus();
                bonus = bonus + pow((lines+level), 2);
                bonus = bonus + checkDeadBlockScore;
            }
            if(bonus > 0) {
                score = Score(score.getCurrentScore()+bonus,
                max(score.getHighScore(),score.getCurrentScore()+bonus));
            }
            if(level==4 && l4counter == 0){
                // drop * block
                if(gameBoard.getCell(3,5) != ' '){
                    restartGame = true;
                    return;
                }
                gameBoard.update(currentBlock->getCellCoords(),'*');
                l4counter=5;
            }
            currentBlock = nextBlock;
            if(currentBlock == nullptr) {
                restartGame = true;
                return;
            }
            if(!gameBoard.check(currentBlock->getCellCoords())){
                restartGame = true;
                return;
            }
            nextBlock = generateBlock(isHeavy);
            gameBoard.update(currentBlock->getCellCoords(),currentBlock->getBlockType());
        multiplier--;
        }
    }
    else if(cmd == "levelu" || cmd == "levelup"){
        while(multiplier!=0){
            if(level < 4){
                level++;
            }
            if(level == 3 || level == 4){
                isHeavy = true;
            } else {
                isHeavy = false;
            }
            if(level == 4){
                l4counter=5;
            }
            multiplier--;
        }
    }
    else if(cmd == "leveld" || cmd == "leveldo" || cmd == "leveldow" || cmd == "leveldown"){
        while(multiplier!=0){
            if(level > 0){
                level--;
            }
            if(level == 3 || level == 4){
                isHeavy = true;
            } else {
                isHeavy = false;
            }
            if(level>=0 && level<=3){
                l4counter = 0;
            }
            multiplier--;
        }
    }
    else if(cmd == "ra" || cmd == "ran" || cmd == "rand" || cmd == "rando" || cmd == "random"){
        if(level > 2){
            noRandom=false;
            noRandomIndex=0;
            noRandomSequence.clear();
        }
    }
    else if(cmd == "n" || cmd == "no" || cmd == "nor" || cmd == "nora" || cmd == "noran" || cmd == "norand" || cmd == "norando"|| cmd == "norandom"){
        bool unsuccessful = false;
        if(level > 2){
            string fileName;
            cin >> fileName;
            ifstream norandomfile(fileName);
            if(!norandomfile){
                cout << "Enter a valid no random sequence file!" << endl;
            } else{
                char i;
                while(norandomfile >> i){
                    noRandomSequence.push_back(i);
                }
                noRandom = true;
                noRandomIndex = 0;
            }
            norandomfile.close();
        }
    }
    else if(cmd == "I" || cmd == "J" || cmd == "L" || cmd == "O" || cmd == "S" || cmd == "Z" || cmd == "T"){
        shared_ptr<Block> newBlock = nullptr;
        if(cmd == "I"){
            newBlock = make_shared<iBlock>('I', level, &gameBoard, isHeavy);
        }
        else if(cmd == "J"){
            newBlock = make_shared<jBlock>('L', level, &gameBoard, isHeavy);
        }
        else if(cmd == "L"){
            newBlock = make_shared<lBlock>('L', level, &gameBoard, isHeavy);
        }
        else if(cmd == "O"){
            newBlock = make_shared<oBlock>('O', level, &gameBoard, isHeavy);
        }
        else if(cmd == "S"){
            newBlock = make_shared<sBlock>('S', level, &gameBoard, isHeavy);
        }
        else if(cmd == "Z"){
            newBlock = make_shared<zBlock>('Z', level, &gameBoard, isHeavy);
        }
        else if(cmd == "T"){
            newBlock = make_shared<tBlock>('T', level, &gameBoard, isHeavy);
        }
        auto coords = newBlock->getCellCoords();
        auto currCoods = currentBlock->getCellCoords();
        coords.a = currCoods.a;
        coords.b = currCoods.b;
        coords.c = currCoods.c;
        coords.d = currCoods.d;
        gameBoard.update(currCoods,' ');
        if(!gameBoard.check(coords)){
            gameBoard.update(currCoods,currentBlock->getBlockType());
        } else {
            currentBlock = newBlock;
            gameBoard.update(currentBlock->getCellCoords(),currentBlock->getBlockType());
        }
    }
    else if(cmd == "re" ||  cmd == "res" ||  cmd == "rest" ||  cmd == "resta" ||  cmd == "restar" || cmd == "restart"){
        //Put implementation for restart
        //reset board
        //reset pointers
        restartGame = false;
        gameBoard.clear();
        gameBoard = Board();
        cur = 0;
        score = Score(0,score.getHighScore());
        currentBlock = generateBlock(isHeavy);
        nextBlock = generateBlock(isHeavy);
        gameBoard.update(currentBlock->getCellCoords(),currentBlock->getBlockType());
        printGameData();
        cout << gameBoard;
        if(nextBlock!= nullptr){
            Game::printNext();
        }
    }
    else if(cmd == "s" || cmd == "se" || cmd == "seq" || cmd == "sequ" || cmd == "seque" || cmd == "sequen" || cmd == "sequenc" || cmd == "sequence"){
        string fileName;
        cin >> fileName;
        ifstream commandfile(fileName);
        if(!commandfile){
            cout << "Enter a valid sequence file!" << endl;
        } else{
            string commandStr;
            while(commandfile >> commandStr){
                command(commandStr);
                printGameData();
                cout << gameBoard;
                printNext();
            }
        }
        commandfile.close();
    }
    else if(cmd == "h" || cmd == "hi" || cmd == "hin" || cmd == "hint"){
      hint = true;
      hintRow = gameBoard.addHint(currentBlock->getBlockType(), nextBlock->getBlockType());
    }
}


void Game::play(){
    //Have commands read here and executed based on function.
    string cmd;
    currentBlock = generateBlock(isHeavy);
    nextBlock = generateBlock(isHeavy);
    gameBoard.update(currentBlock->getCellCoords(),currentBlock->getBlockType());
    printGameData();
    if(textOnly){
        cout << gameBoard;
    }
    else{
        cout << gameBoard;
        graphic.start();
        graphic.printGameData(level, score.getCurrentScore(), score.getHighScore());
        graphic.draw(gameBoard);
    }
    if(nextBlock!= nullptr){
        Game::printNext();
    }

    while(!cin.eof()){
        cout << "Please enter a command to play:";
        cin >> cmd;
        if(restartGame && cmd=="restart"){
            command(cmd);
        } else if(!restartGame){
            command(cmd);
        }
        printGameData();

        if(textOnly){
            cout << gameBoard;
        }
        else{
            cout << gameBoard;
            graphic.draw(gameBoard);
        }
        //Hint being Removed
        if (hint){
          gameBoard.removeHint(hintRow);
          hint = false;
        }
        if(nextBlock!=nullptr){
            printNext();
        }
        if(currentBlock == nullptr) {
            cout << "You've reached the end of the input stream. Please restart the game to try again!" << endl;
        } else if(restartGame && !gameBoard.check(currentBlock->getCellCoords())){
            cout << "Game Over! Please restart the game to try again!" << endl;
        }
    }
}

void Game::printNext(){
      cout << "Next:" << endl;
      if(nextBlock->getBlockType()=='I'){
          cout << "       " << "IIII" << endl;
      } else if(nextBlock->getBlockType()=='J'){
          cout << "       " << "J" << endl;
          cout << "       " << "JJJ" << endl;

      } else if(nextBlock->getBlockType()=='L'){
          cout << "       " << "  L" << endl;
          cout << "       " << "LLL" << endl;
      } else if(nextBlock->getBlockType()=='O'){
          cout << "       " << "OO" << endl;
          cout << "       " << "OO" << endl;
      } else if(nextBlock->getBlockType()=='S'){
          cout << "       " << " SS" << endl;
          cout << "       " << "SS" << endl;
      } else if(nextBlock->getBlockType()=='Z'){
          cout << "       " << "ZZ" << endl;
          cout << "       " << " ZZ" << endl;

      } else if(nextBlock->getBlockType()=='T'){
          cout << "       " << "TTT" << endl;
          cout << "       " << " T" << endl;
      }
      cout << endl;
    if(!textOnly){
      graphic.printNext(nextBlock->getBlockType());
    }
}

void Game::printGameData(){
    cout << endl;
    cout << "Level:    " << level << endl;
    cout << "Score:    " << score.getCurrentScore() << endl;
    cout << "Hi Score: " << score.getHighScore() << endl;
    if(!textOnly){
        graphic.printGameData(level, score.getCurrentScore(), score.getHighScore());
    }
}

shared_ptr<Block> Game::createUniqueCopyBlock(shared_ptr<Block> currBlock){
    shared_ptr<Block> newBlock = nullptr;
    char blockType = currBlock->getBlockType();
    if(blockType == 'I'){
        newBlock = make_shared<iBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'J'){
        newBlock = make_shared<jBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'L'){
        newBlock = make_shared<lBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'O'){
        newBlock = make_shared<oBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'S'){
        newBlock = make_shared<sBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'Z'){
        newBlock = make_shared<zBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'T'){
        newBlock = make_shared<tBlock>(currBlock->getBlockType(), currBlock->getLevel(), currBlock->getCellCoords());
    }
    else if(blockType == 'N'){
        return nullptr;
    }
    return newBlock;
}