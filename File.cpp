#include "File.h"

static fstream screenFile;

void File::openLicFile(string const PATH, Board& board)
{
	for (const auto& file : directory_iterator(PATH))
	{
		if(file.path().extension() == ".screen")
			cout << file.path() << endl;

	}
}

bool File::fileToBoard(string const screenPath, Board& board)
{
	int width = 0, hight = -1;
	unsigned char cLine[80] = {};
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
			strcpy((char*)cLine, line.c_str());
			board.setBoardLine(hight, cLine);
		}
		cout << "width: " << width << endl;
		cout << "Hight: " << hight << endl;
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