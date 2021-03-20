#pragma once
#include "Game.h"
#include "FrenzyUtil.h"
#include <queue>
#include <cctype>

/***********************************************
OperatorFrenzy class

Game to guess order a list of arithmetic operators
to get the highest possible score.

***********************************************/
class OperatorFrenzy : public Game, public FrenzyUtil
{
private:
	std::queue<char> operQueue;
	const int gameID = CHOICE_3 - 1;
	const int capacity = 6;
	//Operator Overloading for +, -, *, and / functions
public:
	OperatorFrenzy(Player &patron);
	int pullFromQueue(int startAmt, int numArr[]);
	void Help() override;
	int* randomize(int numArr[], int size);
	std::string compareChoice(std::string& choice) override;

	template <typename T>
	void displayContent(T arr[], int size);
};
