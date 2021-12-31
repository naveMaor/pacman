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

/* This function reading the file and transfer to board*/
void File::fileToBoard(Board& board)
{
	int rowHightInFile = 0;
	size_t width = 0;
	string line;
	string emptyLine = "                                                                                ";
	
	while (getline(screenFile, line))
	{
		width = line.length();

		// Get the width of the board by the first line of the file
		if (rowHightInFile == 0)
		{
			handleFirstLine(board, width, line[0]); 
			board.setBoardWidth(width);
		}
		
		if (width != 0)
			board.setBoardLine(rowHightInFile, line.c_str(), width);
		else // emptyLine
			board.setBoardLine(rowHightInFile, emptyLine.c_str(), width);
		rowHightInFile++;
	}

	// first row is zero
	board.setBoardHight(rowHightInFile - 1 + board.getBoardStartHight());
}

/* This function handle the first line of the board*/
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

/* This function open the file*/
bool File::openFile(string const filePath)
{
	screenFile.open(filePath);
	if (screenFile.is_open())
		return true;
	cout << "Could not open the file in the directory: " << filePath << endl;
	return false;
}

/* This function check if this is valid file*/
bool File::isValidFile(string const fileName, Board& board)
{
	if (openFile(fileName))
	{
		fileToBoard(board);
		screenFile.close();
		return true;
	}
	return false;
}

 string File::createStepfileName(string const fileName)
{
	string Newname = fileName;
	Newname.erase(6, fileName.length() - 6);
	Newname.append(".steps");
	return Newname;
}

 string File::createResultfile(string const fileName)
 {
	 string Newname = fileName;
	 Newname.erase(6, fileName.length() - 6);
	 Newname.append(".Result");
	 openFile(Newname);
	 return Newname;
 }

 void File::writeToFileStep(string const fileName, char ch)
 {
	 string s = createStepfileName(fileName);
	 if (openFile(s))
	 {
		 screenFile << ch;
	 }
	 screenFile.close();
 }

 void File::writeToFileResult(string const fileName, char ch)
 {

	 if (openFile(fileName))
	 {
		 screenFile.
	 }
 }