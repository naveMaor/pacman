#ifndef UTILITIES
#define UTILITIES
// you must have a config file, both for windows and for compiling on Linux (MAMA)
// BUT, you need to change the content of the config!

#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Wall and BreadCrumbs enum
static enum characterEnum { w = 219, bc = 250 };
void gotoxy(int x, int y);
void setTextColor(Color);
void hideCursor();
void clear_screen();


#endif