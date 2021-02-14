#include "SaveData.h"

/***********************************************
SaveData Class

The class creates a Save Data text file if it
doe not already exist. The file will then read
all of the data into a temporary text file and
will rewrite the data as needed before the
file gets replaced with the original name.

A particular line will be overwritten if it
detects existing data by the player name and
will prompt to user if they would like to
overwrite with their current data.

***********************************************/

//Constructor
SaveData::SaveData(Player &patron)
{
	//check flag for gameID #2
	//If the player has already visited this option more than once
	//in a given session, they will not be shown the help document
	//unless they request to view it.
	if (patron.checkFlags(gameID)) {
		SDHelp();
		patron.updateFlags(gameID);
	}

	//Display the player's current information
	std::cout << "Current information:\n";
	patron.displayCurrentData();
	std::cout << std::endl;

	//local variables for file I/O
	bool noChange = true;				//flag for new record vs. existing record overwrite
	std::string choice;					//user choice
	std::ifstream fileCheck;			//istream object for reading file
	std::ofstream fileWrite;			//ostream object for writing to file
	fileCheck.open("Casino_SaveData.txt");	//opening specific filename 'Casino_SaveData.txt'

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

	//If istream object fileCheck
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

			//Read input from file
			fileCheck >> name >> score >> cash;

			//check if name exists
			if (name == patron.getName()) {
				//If yes, replace the data.
				noChange = false;

				std::cout << "We have found a matching record for " << name << std::endl;
				std::cout << "Score: " << score << ", $: " << cash << std::endl;
				do
				{
					std::cout << "Would you like to overwrite the data with your current score?\n";
					std::cin >> choice;

					SDCompare(choice);

				} while (choice != "yes" && choice != "no");

				if (choice == "yes")
					fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << std::endl;
				else
					fileWrite << name << " " << score << " " << cash << std::endl;
			}
			//Last line of text file is null, if this check does not exist, file experiences issues with writing
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

//to be implemented later
std::string SaveData::SDCompare(std::string& choice)
{
	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		SDHelp();

	else if (choice.compare("yes") != 0 && choice.compare("no") != 0) {
		std::cout << "You entered an incorrect prompt. Please try entering either \"Yes\", \"No\", or \"Help\". \n\n";
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