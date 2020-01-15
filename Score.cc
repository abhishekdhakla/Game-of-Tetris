#include "score.h"
#include <cmath>

Score::Score():currentScore(0), highScore(0){}

Score::Score(int x, int y): currentScore(x), highScore(y){}

void Score::setCurrentScore(int lines, int level){
  currentScore += pow((lines+level), 2);
  if(currentScore > highScore){
    highScore = currentScore;
  }
}

int Score::getHighScore(){
  return highScore;
}

int Score::getCurrentScore(){
  return currentScore;
}

Score::~Score(){}
