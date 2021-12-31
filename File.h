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
	static void handleFirstLine(Board& board, size_t& width, char firstLetter);

public:
	static vector<string> getScreensName(string const PATH); ///// moved to game.cpp
	static void fileToBoard(Board &board);
	static bool isValidFile(string const fileName, Board& board);
	static void createStepfile(string const fileName);
	static void createResultfile(string const fileName);

};

#endif
