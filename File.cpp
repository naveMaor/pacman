#include "File.h"

static fstream screenFile;

void File::openLicFile(string const PATH)
{
	for (const auto& file : directory_iterator(PATH))
		cout << file.path() << endl;

}
void File:: openFile(string const fileName, Board& board)
{
	int width = 0, hight = -1;
	unsigned char cLine[80] = {};

	screenFile.open(fileName);
	if (screenFile.is_open())
	{
		
		string line;
		while (getline(screenFile, line))
		{
			if(hight == -1)
				width = line.length();
			hight++;
			cout << line << endl;
			strcpy((char*)cLine, line.c_str());
			board.setBoardLine(hight,cLine);
		}
		cout << "width: " << width<<endl;
		cout << "Hight: " << hight << endl;
		
	}

}