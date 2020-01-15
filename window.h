#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
	Display *d;
	Window w;
	int s;
	GC gc;
	unsigned long colours[10];
	int height;
	int width;

public:
	Xwindow(int height = 600, int width = 300);  // Constructor; displays the window.
	~Xwindow();                              // Destructor; destroys the window.
	Xwindow(const Xwindow&) = delete;
	Xwindow &operator=(const Xwindow&) = delete;

	enum {White=0, Black, Red, Green, Blue, Yellow, Tan, Cyan, Brown, Orange, Lime, Gray}; // Available colours.

	// Draws a rectangle
	void fillRectangle(int x, int y, int width, int height, int colour=Black);

	// Draws a string
	void drawString(int x, int y, std::string msg, int colour=White);

	// Draw a line
	void drawLine(int startx, int starty, int endx, int endy, int colour=White);
};

#endif
