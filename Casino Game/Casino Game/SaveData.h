#pragma once
#include "Game.h"
#include <fstream>

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
class SaveData : public Game
{
private:
	const int gameID = CHOICE_4 - 1;
public:
	SaveData(Player &patron);
	void CreateNewFile();
	std::string SDCompare(std::string& choice);
	void deleteAndReplaceFiles();
	void Help() override;
};