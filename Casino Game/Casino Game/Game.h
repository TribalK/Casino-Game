#pragma once
#include "Player.h"
class Game
{
private:
	int holdVal;
public:
	virtual void Help() {};
	virtual std::string compareChoice(std::string& choice) { return choice; };
};

