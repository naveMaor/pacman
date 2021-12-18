#include "File.h"

static fstream screenFile;

/* This function return vector of screens names*/
vector<string> File::getScreensName(string const PATH)
{
	vector<string> filesVector;

	for (const auto& file : directory_iterator(PATH))
	{
		if (file.path().extension() == ".screen")
			filesVector.push_back(file.path().filename().string());
	}
	filesVector.shrink_to_fit();
	return filesVector;
}

bool File::fileToBoard(string const screenPath, Board& board)
{
	int width = 0, lineNum = 0;
	char cLine[80] = {};
	string line;
	bool openFileSuccess = openFile(screenPath);
	
	if (openFileSuccess)
	{	
		while (getline(screenFile, line))
		{
			width = (int)line.length();

			// Get the width of the board by the first line of the file
			if (lineNum == 0)
			{
				if (width == 0)
				{
					cout << "The width of the screen is 0, moving to the next screen" << endl;
					Sleep(shortPauseWindow);
					return false;
				}
				board.setBoardWidth(width);
			}
			if (line.length() != 0)
			{
				strcpy(cLine, line.c_str());
				board.setBoardLine(lineNum, cLine, width);
			}
			lineNum++;
		}
		screenFile.close();
		board.setBoardHight(lineNum);
	}
	
	return openFileSuccess;
}


bool File::openFile(string const filePath)
{
	screenFile.open(filePath);
	if (screenFile.is_open())
		return true;
	cout << "Could not open the file in the directory: " << filePath << endl;
	return false;
}