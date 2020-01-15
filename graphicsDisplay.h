#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "window.h"
#include "board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GraphicsDisplay{
    int height;
    int width;
    int cellHeight;
    int cellWidth;
    Xwindow screen;

    public:
    GraphicsDisplay();
    GraphicsDisplay(int, int);
    void start();
    virtual ~GraphicsDisplay();
    void printGameData(int, int, int);
    void draw(Board &activeBoard);
    void printNext(char);
};

#endif