#include "Casino.h"

SaveData::SaveData(Player &patron)
{
	if (patron.checkFlags(gameID)) {
		patron.updateFlags(gameID);
	}
	//IO stream testing for SaveFile.cpp
	fstream fileCheck;

	//Opening text file, if not, create new
	fileCheck.open("Test.txt");
	if (!fileCheck.is_open())
	{
		fileCheck.open("Test.txt", ios::out | ios::in | ios::trunc);
		if (!fileCheck.is_open())
		{
			cout << "Error\n";
		}
		else {
			cout << "Created file.\n";
		}
	}
	else
	{
		cout << "Found our file!\n";
	}
}