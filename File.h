#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <istream>
#include <filesystem>
#include <fstream>
#include <string>
#include "Utilities.h"
#include "Board.h"

using std::ios;
using std::fstream;
using std::filesystem::directory_iterator;

class File
{


public:
	static void openLicFile(string const PATH);
	static void openFile(string const fileName, Board &board);
	

};

