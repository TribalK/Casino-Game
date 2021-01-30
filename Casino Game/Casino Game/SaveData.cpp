#include "Casino.h"

//Constructor
SaveData::SaveData(Player &patron)
{
	//flag check
	if (patron.checkFlags(gameID)) {
		SDHelp();
		patron.updateFlags(gameID);
	}

	//IO stream testing for SaveFile.cpp
	ifstream fileCheck("Casino_SaveData.txt", ios::in);
	ofstream fileWrite("Casino_SaveData.txt", ios::out | ios::app);

	//Opening text file, if not, create new
	
	if (!fileCheck.is_open())
	{
		cout << "File does not exist. Creating now...\n";
		ifstream fileCheck("Casino_SaveData.txt", ios::in | ios::trunc);
	}
	else {
		cout << "Current information:\n";
		patron.displayCurrentData();
		cout << endl;

		while (!fileCheck.eof())
		{
			string name;
			int score;
			int cash;

			fileCheck >> name >> score >> cash;
		}

		cout << "End of file reached.\n";
	}
	fileWrite << patron.getName() << " " << patron.getCurrentScore() << " " << patron.getCurrentEarnings() << "\n";

	if (fileWrite.fail())
	{
		cout << "Something went wrong in writing to the file\n";
	}

	fileCheck.close();
	fileWrite.close();

}

void SaveData::SDHelp()
{
	cout << "This is where you can save your data into a text file,\n"
		<< "That you can use to load your score and money later!\n\n";
}

void SaveData::SDCompare()
{

}