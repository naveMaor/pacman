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
	int width = 0, hight = -1;
	char cLine[80] = {};
	string line;
	bool openFileSuccess = openFile(screenPath);
	
	if (openFileSuccess)
	{	
		while (getline(screenFile, line))
		{
			// Get the width of the board by the first line of the file
			if (hight == -1)
			{
				width = (int)line.length();
				if (width == 0)
				{
					cout << "The width of the screen is 0, moving to the next screen" << endl;
					return false;
				}
				board.setBoardWidth(width);
			}
			hight++;
			cout << line << endl;
			strcpy(cLine, line.c_str());
			board.setBoardLine(hight, cLine,width);
			line.clear();
		}
		board.setBoardHight(hight);
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