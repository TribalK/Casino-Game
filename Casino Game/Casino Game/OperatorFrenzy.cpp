#include "OperatorFrenzy.h"

OperatorFrenzy::OperatorFrenzy(Player &patron)
{
	if (Casino::checkFlags(gameID)) {
		Help();
		Casino::updateFlags(gameID);
	}

	patron.updateCash();

	char operArr[6] = { '+','+','-','-','*','/'};
	int numArr[6] = { 10, 10, -1, 2, 5, 1 };
	bool used[6];

	for (int i = 0; i < capacity; i++)
	{
		used[i] = false;
	}

	std::cout << "You are given the following numbers: ";
	displayContent(numArr, sizeof(numArr)/sizeof(numArr[0]));

	std::cout << "and the following operators: ";
	displayContent(operArr, sizeof(operArr)/sizeof(operArr[0]));

	/*while ((signed) operQueue.size() < capacity) {
		std::string choice;
		std::cout << "\nType the number for each operator you want to use in order.\n";
		std::cin >> choice;
		compareChoice(choice);

		operQueue.push(operArr[0]);
	}*/

	//std::cout << operQueue.front() << std::endl;
	//Ideas: Allow user to specify as many numbers of operators they want to set,
	//then if they want to randomize the rest they could say the "keyword"
}

void OperatorFrenzy::Help()
{
	std::cout << "Welcome to Operator Frenzy! In this game, the player will be given \n" <<
		"a series of numbers and a set of arithmetic operators. You will have \n" <<
		"the choice of organizing the operators in whichever order you like. \n" <<
		"The operators will then be placed in a queue and the list of numbers\n" <<
		"will be randomized. Order your operators optimally to receive the greatest\n" <<
		"possible earnings. Good luck!\n\n";
}

//Using template class to display contents of both arrays by having it pass through an array of type T
//Removes duplicating work
template <typename T>
void OperatorFrenzy::displayContent(T arr[], int size)
{
	for(int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

std::string OperatorFrenzy::compareChoice(std::string& choice)
{
	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		Help();

	else if (choice.compare("set") != 0 && !isdigit(choice[0])) {
		std::cout << "You entered an incorrect prompt. Please try entering either a number, \"Set\", or \"Help\". \n\n";
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return choice;
}