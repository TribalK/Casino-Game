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
	fstream fileCheck;

	//Opening text file, if not, create new
	fileCheck.open("Casino_SaveData.txt");
	if (!fileCheck.is_open())
	{
		cout << "Save Data document does not exist yet. Creating now...\n";
		fileCheck.open("Casino_SaveData.txt", ios::out | ios::in | ios::trunc);
		if (!fileCheck.is_open())
		{
			cout << "Error in creating file.\n\n";
		}
		else {
			cout << "Created file.\n\n";
		}
	}

	cout << "Current information:\n";
	patron.displayCurrentData();
	cout << endl;
}

void SaveData::SDHelp()
{
	cout << "This is where you can sava your data into a text file,\n"
		<< "That you can use to load your score and money later!\n\n";
}