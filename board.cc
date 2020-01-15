#include "board.h"
#include "blockCell.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <math.h>

using namespace std;

// constructor for board
Board::Board(int height, int width):gameBoard(height,vector<char>(width, ' ')){}

// prints out the state of the board
ostream& operator<<(ostream &out, const Board &currBoard){
    int count = 11;
    while(count!=0) {
        count--;
        out << '-';
    }
    out << endl;
    for(int i=0;i<currBoard.gameBoard.size();i++){
        for(int j=0;j<currBoard.gameBoard[i].size();j++){
            out << currBoard.gameBoard[i][j];
        }
        out << endl;
    }
    while(count!=11) {
        count++;
        out << '-';
    }
    out << endl;
    return out;
}

int Board::getHeight(){
  return height;
}

int Board::getWidth(){
    return width;
}

bool Board::isRowFull(int n){
  //Check for well a row becomes
  for(int i = 0; i<this->getWidth(); i++){
    if(this->gameBoard[n][i] == ' '){
      return false;
    }
  }
  return true;
}

int Board::clearRow(){
  //Clears the rows and returns the number of them cleared
  int nosOfRows = 0;
  starBonus = 0;
  for(int i = (this->getHeight())-1; i>=3; i--){
    if(isRowFull(i)){
      //Swap the current with the one above;
      for(int j = i; j>=3; j--){
        for(int k = 0; k<this->getWidth(); k++){
          this->gameBoard[j][k] = this->gameBoard[j-1][k];
        }
      }
      for(int l=0;l<boardBlocks.size();l++){
            auto checkBlock= boardBlocks[l];
            auto cellCoordCheck = checkBlock->getCellCoords();
            cellCoordCheck.a.y = cellCoordCheck.a.y+1;
            cellCoordCheck.b.y = cellCoordCheck.b.y+1;
            cellCoordCheck.c.y = cellCoordCheck.c.y+1;
            cellCoordCheck.d.y = cellCoordCheck.d.y+1;
            checkBlock->setCellCoords(cellCoordCheck);
      }
      if(this->getCell(i,5)=='*'){
        starBonus+=25;
      }
      nosOfRows++;
      i++;
    }
  }
  return nosOfRows;
}

int Board::checkDeadBlocks(){
  int deadScore = 0;
  vector<int> deleteIndexs;
  for(int i=0;i<boardBlocks.size();i++){
    auto it = boardBlocks[i];
    auto cellIt = it->getCellCoords();
    //this means block is out of the scope
    if(cellIt.a.y>=this->getHeight() && cellIt.b.y>=this->getHeight() && cellIt.c.y>=this->getHeight() && cellIt.d.y>=this->getHeight()){
      int levelCreated = it->getLevel();
      deadScore += pow(levelCreated+1,2);
      // delete this block from vector
      deleteIndexs.push_back(i);
    }
  }
  for(int i=0;i<deleteIndexs.size();i++){
    int index  = deleteIndexs[i]-i;
    boardBlocks.erase(boardBlocks.begin()+index);
  }
  return deadScore;
}

bool Board::isEmptyRow(int n){
  int count = 0;

  for(int i = 0; i<this->getWidth(); i++){
    if(this->gameBoard[n][i] == ' '){
      count++;
    }
  }

  if(count == this->getWidth()){
    return true;
  }
  else{
    return false;
  }
}

// destructor for board
Board::~Board(){}

// Check if Test block is valid
bool Board::check(BlockCell &test){
    // if out of bounds
    if(test.a.x < 0 || test.b.x < 0 || test.c.x < 0 || test.d.x < 0){
        return false;
    }
    // if out of bounds
    if(test.a.y < 0 || test.b.y < 0 || test.c.y < 0 || test.d.y < 0){
        return false;
    }
    //if out of bounds
    if(test.a.y >= 18 || test.b.y >= 18 || test.c.y >= 18 || test.d.y >= 18){
        return false;
    }
    // if out of bounds
    if(test.a.x >= 11 || test.b.x >= 11 || test.c.x >= 11 || test.d.x >= 11){
        return false;
    }
    // check if empty spot
    if(gameBoard[test.a.y][test.a.x]!= ' ') return false;
    if(gameBoard[test.b.y][test.b.x]!= ' ') return false;
    if(gameBoard[test.c.y][test.c.x]!= ' ') return false;
    if(gameBoard[test.d.y][test.d.x]!= ' ') return false;

    return true;
}

// Check if Test block is valid
void Board::update(BlockCell& test, char input){
    if(input == '*'){
      int i = 3;
      while(i<this->getHeight() && gameBoard[i][5] == ' '){
        i++;
      }
      i--;
      gameBoard[i][5] = '*';
    } else {
        gameBoard[test.a.y][test.a.x]= input;
        gameBoard[test.b.y][test.b.x]= input;
        gameBoard[test.c.y][test.c.x]= input;
        gameBoard[test.d.y][test.d.x]= input;
      }
}

void Board::clear(){
  gameBoard.clear();
}

char Board::getCell(int a, int b){
  return this->gameBoard[a][b];
}

bool sortbysec(const tuple<int, int>& a,  const tuple<int, int>& b)
{
    return (get<1>(a) < get<1>(b));
}

// Place appropriate hint
int Board::addHint(char current, char next){
  int hintRow = 0;
  for(int i = this->getHeight()-1; i>3; i--){
    if(isEmptyRow(i-1)){
      hintRow = i;
      break;
    }
  }

  vector<tuple<int, int>> spaces;
  int spaceCount = 0;
  int index = 0;
  bool active = true;
  //Check how many continous spaces are there;
  for(int i = 0; i<this->getWidth(); i++){
    if(this->gameBoard[hintRow][i] != ' ' && spaceCount != 0){
      spaces.push_back(make_tuple(index, spaceCount));
      sort(spaces.begin(), spaces.end(), sortbysec);
      spaceCount = 0;
      index = i+1;
      active = true;
    }
    else if(this->gameBoard[hintRow][i] == ' '){
      if(active){
        index = i;
        active = false;
      }
      spaceCount++;
    }
  }
  if(spaceCount!=0){
    spaces.push_back(make_tuple(index, spaceCount));
    sort(spaces.begin(), spaces.end(), sortbysec);
  }

  //Hints
  if(spaces.size() == 0){
    gameBoard[hintRow-1][0] = '?';
    hintRow--;
    return hintRow;
  }

  int last = spaces.size()-1;
  if(get<1>(spaces[last]) == this->getWidth()){
    gameBoard[hintRow][0] = '?';
    return hintRow;
  }

  if(spaces.size() >= 2){
    int sopLast = spaces.size()-2;
  }

  if(current == 'I'){
    //If a 4 row slot is available and it's the only one;
    if(get<1>(spaces[last]) >= 4){
      for(int i = 0; i<spaces.size(); i++){
        if(get<1>(spaces[i]) == 4){
          gameBoard[hintRow][(get<0>(spaces[i]))] = '?';
          return hintRow;
        }
      }
      gameBoard[hintRow][(get<0>(spaces[last]))+5] = '?';
    }
    else if(get<1>(spaces[last]) < 4){
      if(next != 'I'){
        if(get<0>(spaces[last]) + 3 < this->getWidth()-1){
          gameBoard[hintRow-1][(get<0>(spaces[last]))+3] = '?';
          hintRow--;
        }
        else{
          gameBoard[hintRow-1][(get<0>(spaces[last]))-2] = '?';
          hintRow--;
        }
      }
      else{
        gameBoard[hintRow][(get<0>(spaces[last]))] = '?';
      }
    }
  }
  else if(current == 'J' || current == 'L' || current == 'T'){
    if(get<1>(spaces[last]) >= 3){
      for(int i = 0; i<spaces.size(); i++){
        if(get<1>(spaces[i]) == 3){
          gameBoard[hintRow][(get<0>(spaces[i]))] = '?';
          return hintRow;
        }
      }
      gameBoard[hintRow][(get<0>(spaces[last]))] = '?';
    }
    else if(get<1>(spaces[last]) < 3){
      gameBoard[hintRow][(get<0>(spaces[last]))] = '?';
    }
  }
  else if(current == 'S' || current == 'Z' || current == 'O'){
      if(get<1>(spaces[last]) >= 2){
        for(int i = 0; i<spaces.size(); i++){
          if(get<1>(spaces[i]) == 2){
            gameBoard[hintRow][get<0>(spaces[i])] = '?';
            return hintRow;
          }
        }
        gameBoard[hintRow][(get<0>(spaces[last]))] = '?';
      }
      else{
        gameBoard[hintRow-1][(get<0>(spaces[last]))] = '?';
        hintRow--;
      }
  }

  return hintRow;
}

void Board::removeHint(int num){
  for(int i = 0; i<this->getWidth(); i++){
    if(gameBoard[num][i] == '?'){
      this->gameBoard[num][i] = ' ';
    }
  }
  return;
}

vector<vector<char> >& Board::getBoard(){
  return gameBoard;
}


int Board::getStarBonus(){
  int toReturn = this->starBonus;
  starBonus=0;
  return toReturn;
}