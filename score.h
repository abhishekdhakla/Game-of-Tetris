#ifndef SCORE_H
#define SCORE_H

class Score{
  int highScore;
  int currentScore;
  int level;
  public:
    Score();
    Score(int, int);
    int getHighScore();
    int getCurrentScore();
    void setCurrentScore(int, int);
    virtual ~Score();
};

#endif
