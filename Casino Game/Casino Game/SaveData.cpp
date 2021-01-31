#include "SaveData.h"

//Constructor
SaveData::SaveData(Player &patron)
{
	//flag check
	if (patron.checkFlags(gameID)) {
		SDHelp();
		patron.updateFlags(gameID);
	}

	std::cout << "Current information:\n";
	patron.displayCurrentData();
	std::cout << std::endl;

	//IO stream testing for SaveFile.cpp
	bool noChange = true;
	std::ifstream fileCheck;
	std::ofstream fileWrite;
	fileCheck.open("Casino_SaveData.txt");

	/*
		"The only way to replace one string with another string in a text file 
		is to completely rewrite the file. Open the original text file for reading, 
		open a temp file for writing. In a loop, read each line of the original file 
		and rewrite it to the temp file, except write when you get to the line that 
		needs to be replaced write the replacement string instead of the string read 
		from the file. After all is done, close both files, delete the original file, 
		then rename the temp file to the name of the original file."

		- Perhaps only necessary for strings, not ints?
		- Open Casino_SaveData.txt for reading, open temp file for writing
	*/

	//Creating new file if it does not exist
	if (!fileCheck.is_open())
	{
		CreateNewFile();
		fileWrite.open("Casino_SaveData.txt");

		fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << std::endl;
		fileWrite.close();
	}
	//File exists
	else {
		//Open temporary text file
		fileWrite.open("tmp_SaveData.txt");

		//Read all lines from input file
		while (!fileCheck.eof())
		{
			//variables in file
			std::string name;
			int score;
			int cash;

			fileCheck >> name >> score >> cash;

			//check if name exists
			if (name == patron.getName()) {
				//If yes, replace the data.
				noChange = false;
				std::cout << "Found " << name << std::endl;
				fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << std::endl;
			}
			else if (name[0] == NULL) {
				continue;
			}
			else {
				//If not, write the file in the way it was made, do not replace any fields
				fileWrite << name << " " << score << " " << cash << std::endl;
			}
		}
		
		//Write the new information to the end of the file
		if(noChange)
			fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << std::endl;

		std::cout << "End of file reached.\n";
		fileCheck.close();
		fileWrite.close();

		deleteAndReplaceFiles();
	}
}

void SaveData::SDHelp()
{
	std::cout << "This is where you can save your data into a text file,\n"
		<< "That you can use to load your score and money later!\n\n";
}

std::string SaveData::SDCompare(std::string& choice)
{
	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		SDHelp();

	else if (choice.compare("lower") != 0 && choice.compare("higher") != 0) {
		std::cout << "You entered an incorrect prompt. Please try entering either \"Lower\", \"Higher\", or \"Help\". \n\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return choice;
}

void SaveData::CreateNewFile()
{
	std::cout << "File does not exist. Creating now...\n";
	std::ifstream fileCheck("Casino_SaveData.txt", std::ios::trunc);
	fileCheck.close();
}

void SaveData::deleteAndReplaceFiles()
{
	if (remove("Casino_SaveData.txt") != 0)
	{
		std::cerr << "There was an issue deleting the file.\n";
	}
	else {
		std::cout << "File deleted successfully\n";
		int result = rename("tmp_SaveData.txt", "Casino_SaveData.txt");

		if (result == 0)
			std::cout << "File successfully renamed.\n";
		else
			std::cerr << "Error in renaming the file.\n";
	}
}