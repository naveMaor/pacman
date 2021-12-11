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
using std::string;

// Wall and BreadCrumbs enum
enum sleepEnum { shortPauseWindow = 2500, longPauseWindow = 4000 };
enum gameSpeed { easyGameSpeed = 600, mediumGameSpeed = 300, hardGameSpeed = 140, expertGameSpeed = 70 };
enum characterEnum { w = 219, bc = 250, pacmanIcon = 2, ghostIcon= 36, defaltFruitIcon = 53, 
	space =  32, boardGarbageVal = 52, heart = 3};
void gotoxy(int x, int y);
void setTextColor(Color);
void hideCursor();
void clearScreen();
int randomBetween(int min, int max);


#endif