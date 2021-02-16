#pragma once
#include "Player.h"
#include <queue>

class OperatorFrenzy : public Player
{
	const int gameID = CHOICE_3 - 1;
public:
	OperatorFrenzy(Player &patron);
	void OFHelp();
};
