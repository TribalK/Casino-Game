#pragma once
#include "Game.h"

/***********************************************
HigherOrLower class

Game to guess a number given a predictor and
the computer's true value

***********************************************/
class HigherOrLower : public Game
{
private:
	const int gameID = CHOICE_1 - 1;
public:
	HigherOrLower(Player &patron);
	std::string HoLCompare(std::string& choice);
	void Help() override;
	inline int random(int i, int n) { return rand() % n + i; }
};