#pragma once
#include "Player.h"

/***********************************************
HigherOrLower class

Game to guess a number given a predictor and
the computer's true value

***********************************************/
class HigherOrLower : public Player
{
private:
	int compRandNum;
	const int gameID = CHOICE_1 - 1;
public:
	HigherOrLower(Player &patron);
	std::string HoLCompare(std::string& choice);
	void HoLHelp();
	int random(int i, int n) { return rand() % n + i; }
};