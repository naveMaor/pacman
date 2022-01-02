#include "File.h"

static fstream file;

/* This function return vector of screens names*/
vector <string> File::getScreensName(string const PATH)
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
bool File::fileToBoard(Board& board)
{
	int rowHightInFile = 0;
	bool b_validFile = true;
	size_t currLineWidth = 0;
	string currLine;
	string emptyLine = "                                                                                ";
	
	while (getline(file, currLine) && b_validFile)
	{
		currLineWidth = currLine.length();

		// Get the width of the board by the first line of the file
		if (rowHightInFile == 0)
		{
			handleFirstLine(currLineWidth, currLine[0],b_validFile); 
			board.setBoardWidth(currLineWidth);
		}
		
		if (currLineWidth != 0)
			board.setBoardLine(currLine.c_str());
		else // emptyLine
			board.setBoardLine(emptyLine.c_str());
		rowHightInFile++;
		b_validFile = board.getIsValidBoard();
	}

	return board.checkValidBoard() && b_validFile;
}

/* This function handle the first line of the board*/
void File::handleFirstLine(size_t & currLineWidth, char firstLetter, bool & b_validScreen)
{
	// If the first line of the screen is \n
	if (currLineWidth == 0)
	{
		cout << "The width of the screen is two short, moving to the next screen" << endl;
		b_validScreen = false;
		Sleep(shortPauseWindow);
	}
	// If the first letter in the file is & and the width is 1 init the board width to 20
	else if ((currLineWidth == 1) && (firstLetter == '&'))
		currLineWidth = 20;
	// If the first line is more than 80 chars limit it to 80
	else if (currLineWidth > 80)
		currLineWidth = 80;
}

/* This function open the file*/
bool File::openFile(string const filePath)
{
	file.open(filePath);
	if (file.is_open())
		return true;
	cout << "Could not open the file in the directory: " << filePath << endl;
	Sleep(shortPauseWindow);
	return false;
}

/* This function check if this is valid file*/
bool File::isValidFile(string const fileName, Board& board)
{
	bool b_isValid = true;
	if (openFile(fileName))
	{
		b_isValid = fileToBoard(board);
		file.close();
		return b_isValid;
	}
	return false;
}

/* This function create the correct name of steps file name*/
 string File::createStepfileName(string const fileName)
{
	string stepsFileName = fileName;
	stepsFileName.erase(fileName.length() - 6);
	stepsFileName.append("steps");
	return stepsFileName;
}

 /* This function create the correct name of results file name*/
 string File::createResultfileName(string const fileName)
 {
	 string resultsFileName = fileName;
	 resultsFileName.erase(fileName.length() - 6);
	 resultsFileName.append("result");
	 openFile(resultsFileName);
	 return resultsFileName;
 }

 /* This function write char to the opened file*/
 void File::writeCharToFile(char ch)
 {
	 file.put(ch);
 }

 /* This function write two digit num to the opened file as char*/
 void File:: writeNumToFileAsChar(char ch)
 {
	 if (ch > 9)
	 {
		 writeCharToFile(ch / 10 + '0');
		 writeCharToFile(ch % 10 + '0');
	 }
	 else
		 writeCharToFile(ch + '0');
 }

 /* This function create and open step and result files*/
 void File::createAndOpenFile(string const fileName, int fileType)
 {
	 string newFileName;
	 if (fileType == fileType::step) // steps file
		 newFileName = createStepfileName(fileName);
	 else // results file
		 newFileName = createResultfileName(fileName);
	 file.open(newFileName.c_str(), std::ios_base::out, std::ios_base::trunc);
 }

 /* This function close */
 void File::closeWrittenFile()
 {
	 file.flush();
	 file.close();
 }

