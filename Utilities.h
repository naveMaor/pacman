#ifndef UTILITIES
#define UTILITIES

#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

// Wall and BreadCrumbs enum
//enum characterEnum { w = 219, bc = 250, pacmanIcon = 64, ghostIcon= 36, space =  32, boardGarbageVal = 53};
enum characterEnum { w = 219, bc = 250, pacmanIcon = 2, ghostIcon= 36, space =  32, boardGarbageVal = 53, heart = 3};
void gotoxy(int x, int y);
void setTextColor(Color);
void hideCursor();
void clearScreen();

#endif