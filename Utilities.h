#ifndef UTILITIES_H
#define UTILITIES_H
#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


// Wall and BreadCrumbs enum
enum GhostsLevel {easy = 1, Medium = 2, Hard = 3};
enum sleepEnum { shortPauseWindow = 2500, longPauseWindow = 4000 };
enum gameSpeed { easyGameSpeed = 600, mediumGameSpeed = 300, hardGameSpeed = 140, expertGameSpeed = 70 };
enum characterEnum { wall = 219, breadCrumb = 250, pacmanIcon = 2, ghostIcon= 36, defaltFruitIcon = 53, 
	space =  32, boardGarbageVal = 52, heart = 3, gameInfoArea = 126, cleanGameArea = 37};

const string screenPath = ".";

void gotoxy(int x, int y);
//void gotoxy(Point point);
void setTextColor(Color);
void hideCursor();
void clearScreen();
int randomBetween(int min, int max);


#endif