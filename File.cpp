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

void File::fileToBoard(Board& board)
{
	int lineNum = 0;
	size_t width = 0;
	//char cLine[80] = {};
	string line;
	
	while (getline(screenFile, line))
	{
		width = line.length();

		// Get the width of the board by the first line of the file
		if (lineNum == 0)
		{
			handleFirstLine(board, width, line[0]); // add validation
			board.setBoardWidth(width);
		}
		
		if (width != 0)
		{
			board.setBoardLine(lineNum, line.c_str(), width);
			lineNum++;
		}
	}
		board.setBoardHight(lineNum + board.getBoardStartHight());
}

void File::handleFirstLine(Board& board, size_t &width, char firstLetter)
{
	if (width == 0 || width == 2)
	{
		cout << "The width of the screen is two short, moving to the next screen" << endl;
		Sleep(shortPauseWindow);
	}
	else if (width == 1)
		if (firstLetter == '&')
			width = 20;
}

bool File::openFile(string const filePath)
{
	screenFile.open(filePath);
	if (screenFile.is_open())
		return true;
	cout << "Could not open the file in the directory: " << filePath << endl;
	return false;
}
bool File::isValidFile(string const fileName, Board& board)
{
	bool openFileSuccess = openFile(fileName);
	fileToBoard(board);
	screenFile.close();
	return true;
}
