#pragma once
#include "Game.h"
#include <queue>

/***********************************************
OperatorFrenzy class

Game to guess order a list of arithmetic operators
to get the highest possible score.

***********************************************/
class OperatorFrenzy : public Game
{
	const int gameID = CHOICE_3 - 1;
public:
	OperatorFrenzy(Player &patron);
	void Help() override;
};
