#pragma once
#include "Player.h"
#include <fstream>

//Work in progress - save function
//Save to IO file
class SaveData : public Player
{
private:
	const int gameID = CHOICE_3 - 1;
public:
	SaveData(Player &patron);
	void CreateNewFile();
	std::string SDCompare(std::string& choice);
	void deleteAndReplaceFiles();
	void SDHelp();
};