#ifndef FILE_H
#define FIlE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "Utilities.h"
#include "Board.h"

using std::vector;
using std::fstream;
using std::filesystem::directory_iterator;

class File
{
	static bool openFile(string const filePath);

public:
	static vector<string> getScreensName(string const PATH); ///// moved to game.cpp
	static bool fileToBoard(string const fileName, Board &board);

};

#endif
