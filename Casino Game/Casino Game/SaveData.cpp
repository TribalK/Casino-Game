#include "Casino.h"

//Constructor
SaveData::SaveData(Player &patron)
{
	//flag check
	if (patron.checkFlags(gameID)) {
		SDHelp();
		patron.updateFlags(gameID);
	}

	cout << "Current information:\n";
	patron.displayCurrentData();
	cout << endl;

	//IO stream testing for SaveFile.cpp
	bool noChange = true;
	ifstream fileCheck;
	ofstream fileWrite;
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
		cout << "File does not exist. Creating now...\n";
		ifstream fileCheck("Casino_SaveData.txt", ios::trunc);
		fileWrite.open("Casino_SaveData.txt");

		fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << endl;
		fileCheck.close();
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
			string name;
			int score;
			int cash;

			fileCheck >> name >> score >> cash;

			//check if name exists
			if (name == patron.getName()) {
				//If yes, replace the data.
				noChange = false;
				cout << "Found " << name << endl;
				fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << endl;
			}
			else if (name[0] == NULL) {
				continue;
			}
			else {
				//If not, write the file in the way it was made, do not replace any fields
				fileWrite << name << " " << score << " " << cash << endl;
			}
		}
		
		//Write the new information to the end of the file
		if(noChange)
			fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << endl;

		cout << "End of file reached.\n";
		fileCheck.close();
		fileWrite.close();

		if (remove("Casino_SaveData.txt") != 0)
		{
			cerr << "There was an issue deleting the file.\n";
		}
		else {
			cout << "File deleted successfully\n";
			int result = rename("tmp_SaveData.txt", "Casino_SaveData.txt");

			if (result == 0)
				cout << "File successfully renamed.\n";
			else
				cerr << "Error in renaming the file.\n";
		}
	}

	/*if (noChange) {
		fileAppend << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << "\n";
		if (fileAppend.fail())
		{
			cout << "Something went wrong in writing to the file\n";
		}
		fileAppend.close();
	}
	else {
		/*fileReplace << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << "\n";

		if (fileReplace.fail())
		{
			cout << "Something went wrong in writing to the file\n";
		}
		//fileReplace.close();
	}
	*/
}

void SaveData::SDHelp()
{
	cout << "This is where you can save your data into a text file,\n"
		<< "That you can use to load your score and money later!\n\n";
}

void SaveData::SDCompare()
{

}