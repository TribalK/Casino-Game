#pragma once
#include "Game.h"
#include <queue>
#include <cctype>

/***********************************************
OperatorFrenzy class

Game to guess order a list of arithmetic operators
to get the highest possible score.

***********************************************/
class OperatorFrenzy : public Game
{
private:
	std::queue<char> operQueue;
	const int gameID = CHOICE_3 - 1;
	const int capacity = 6;
public:
	OperatorFrenzy(Player &patron);
	void Help() override;
	std::string compareChoice(std::string& choice) override;

	template <typename T>
	void displayContent(T arr[], int size);
};
