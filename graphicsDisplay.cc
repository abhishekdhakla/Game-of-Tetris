#include "graphicsDisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay():height(600), width(300){
    cellHeight = height / 24;
    cellWidth = width / 11;
}

GraphicsDisplay::GraphicsDisplay(int height, int width): height(height), width(width){
    cellHeight = height / 24;
    cellWidth = width / 11;
}

void GraphicsDisplay::start(){
    screen.fillRectangle(0, 0, width, height, Xwindow::Tan);
    screen.drawLine(cellWidth - 10, 3*cellHeight + 15, 10*cellWidth + 10, 3*cellHeight + 15, Xwindow::Gray);
    screen.fillRectangle(0, 6*cellHeight, width, 18*cellHeight, Xwindow::White);
}

void GraphicsDisplay::printGameData(int level, int currentScore, int highScore){
    screen.fillRectangle(0, 0, width, 3*cellWidth, Xwindow::Tan);
    string lev = "Level: " + to_string(level);
    string cScore = "Score: " + to_string(currentScore);
    string hScore = "High Score: " + to_string(highScore);
    screen.drawString(0, cellHeight, lev);
    screen.drawString(0, 2*cellHeight, cScore);
    screen.drawString(0, 3*cellHeight, hScore);
}

void GraphicsDisplay::draw(Board &activeBoard){
    vector<vector<char>> gameBoard = activeBoard.getBoard();
    screen.fillRectangle(0, 6*cellHeight, width, 18*cellHeight, Xwindow::White);

    for(int i = 0; i < activeBoard.getHeight(); i++){
        for(int j = 0; j < activeBoard.getWidth(); j++){
            if(gameBoard[i][j] == 'I'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Yellow);
            }
            else if(gameBoard[i][j] == 'J'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Blue);
            }
            else if(gameBoard[i][j] == 'L'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Cyan);
            }
            else if(gameBoard[i][j] == 'O'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Green);
            }
            else if(gameBoard[i][j] == 'S'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Red);
            }
            else if(gameBoard[i][j] == 'Z'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Lime);
            }
            else if(gameBoard[i][j] == 'T'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
                screen.fillRectangle(j*cellWidth + 1, (i+6)*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Orange);
            }
            else if(gameBoard[i][j] == '?'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Black);
            }
            else if(gameBoard[i][j] == '*'){
                screen.fillRectangle(j*cellWidth, (i+6)*cellHeight, cellWidth, cellHeight, Xwindow::Brown);
            }
        }
    }
}

void GraphicsDisplay::printNext(char next){
    screen.drawString(0, 5*cellHeight, "Next:", Xwindow::White);
    screen.fillRectangle(4*cellWidth, 4*cellHeight, 5*cellWidth, 2*cellHeight, Xwindow::Tan);

    if(next == 'I'){
        screen.fillRectangle(4*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 4*cellHeight+1, cellWidth - 2, cellHeight - 2, Xwindow::Yellow);
        screen.fillRectangle(5*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 4*cellHeight+1, cellWidth - 2, cellHeight - 2, Xwindow::Yellow);
        screen.fillRectangle(6*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 4*cellHeight+1, cellWidth - 2, cellHeight - 2, Xwindow::Yellow);
        screen.fillRectangle(7*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(7*cellWidth + 1, 4*cellHeight+1, cellWidth - 2, cellHeight - 2, Xwindow::Yellow);
    }
    else if(next == 'J'){
        screen.fillRectangle(4*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Blue);
        screen.fillRectangle(4*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Blue);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Blue);
        screen.fillRectangle(6*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Blue);
    }
    else if(next == 'L'){
        screen.fillRectangle(6*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Cyan);
        screen.fillRectangle(4*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Cyan);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Cyan);
        screen.fillRectangle(6*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Cyan);
    }
    else if(next == 'O'){
        screen.fillRectangle(4*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Green);
        screen.fillRectangle(4*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Green);
        screen.fillRectangle(5*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Green);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Green);
    }
    else if(next == 'S'){
        screen.fillRectangle(5*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Red);
        screen.fillRectangle(6*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Red);
        screen.fillRectangle(4*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Red);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Red);
    }
    else if(next == 'Z'){
        screen.fillRectangle(4*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Lime);
        screen.fillRectangle(5*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Lime);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Lime);
        screen.fillRectangle(6*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Lime);
    }
    else if(next == 'T'){
        screen.fillRectangle(4*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(4*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Orange);
        screen.fillRectangle(5*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Orange);
        screen.fillRectangle(6*cellWidth, 4*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(6*cellWidth + 1, 4*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Orange);
        screen.fillRectangle(5*cellWidth, 5*cellHeight, cellWidth, cellHeight, Xwindow::Black);
        screen.fillRectangle(5*cellWidth + 1, 5*cellHeight + 1, cellWidth - 2, cellHeight - 2, Xwindow::Orange);
    }
}

GraphicsDisplay::~GraphicsDisplay(){}
