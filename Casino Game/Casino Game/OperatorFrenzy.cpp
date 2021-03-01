#include "OperatorFrenzy.h"

OperatorFrenzy::OperatorFrenzy(Player &patron)
{
	if (Casino::checkFlags(gameID)) {
		OFHelp();
		Casino::updateFlags(gameID);
	}

	char operArr[6] = { '+','+','-','-','*','/'};
	int numArr[6] = { 10, 10, -1, 2, 5, 1 };

}

void OperatorFrenzy::OFHelp()
{
	std::cout << "Welcome to Operator Frenzy! In this game, the player will be given \n" <<
		"a series of numbers and a set of arithmetic operators. You will have \n" <<
		"the choice or organizing the operators in whichever order you like. \n" <<
		"The operators will then be placed in a queue and the list of numbers\n" <<
		"will be randomized. Order your operators optimally to receive the greatest\n" <<
		"possible earnings. Good luck!\n\n";
}