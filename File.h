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
using std::ofstream;
using std::filesystem::directory_iterator;

class File
{
	static bool openFile(string const filePath);
	static void handleFirstLine( size_t& currLineWidth, char firstLetter, bool& b_validScreen);

public:
	static vector<string> getScreensName(string const PATH); ///// moved to game.cpp
	static bool fileToBoard(Board &board);
	static bool isValidFile(string const fileName, Board& board);
	static string createStepfileName(string const fileName);
	static string createResultfileName(string const fileName);
	static void writeCharToFile(char ch);
	static void writeNumToFileAsChar(char ch);
	static void createAndOpenFile(string const fileName, int filetype);
	static void closeWrittenFile();

};

#endif
