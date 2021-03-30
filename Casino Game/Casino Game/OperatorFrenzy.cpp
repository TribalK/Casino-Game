#include "OperatorFrenzy.h"

OperatorFrenzy::OperatorFrenzy(Player &patron)
{
	//Update flags
	if (Casino::checkFlags(gameID)) {
		Help();
		Casino::updateFlags(gameID);
	}

	patron.updateCash();

	//The starting amount for the game is the same amount you paid for entry into the game.
	int startAmt = abs(patron.getCurrentEarnings());

	char operArr[6] = { '+','+','-','-','*','*'};	//Array of operators
	int numArr[6] = { 10, 8, -1, 2, 5, 0 };			//Array of numbers
	bool used[6];		//Will determine if a position in the operator array has already been chosen
	
	//Initialize the used array
	memset(used, false, sizeof(used));

	std::cout << "You are given the following numbers: ";
	displayContent(numArr, sizeof(numArr)/sizeof(numArr[0]));

	std::cout << "and the following operators: ";
	displayContent(operArr, sizeof(operArr)/sizeof(operArr[0]));

	fillOperatorQueue(operArr, used);

	//The number array is then randomized
	randomize(numArr, sizeof(numArr) / sizeof(numArr[0]));
	displayContent(numArr, sizeof(numArr) / sizeof(numArr[0]));

	//The random numbers are then used with the operators pulled from the operator queue.
	int changeAmt = pullFromQueue(startAmt, numArr);

	//If the final score is less than 0, it will be set to 0 by default so the user
	//does not lose more money than what they initially paid.
	if (changeAmt < 0) {
		patron.setCurrentScore(0);
		patron.setCurrentEarnings(0);
	}
	//Any positive value will be rounded to the nearest fifth value
	else {
		patron.setCurrentScore(400);
		patron.setCurrentEarnings(changeAmt-(changeAmt%5));
	}

	//update the player's score and currency amounts
	patron.updateCash();
	patron.updateScore();
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

int* OperatorFrenzy::randomize(int numArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int newIdx = i + rand() % (size - i);
		int temp = numArr[i];
		numArr[i] = numArr[newIdx];
		numArr[newIdx] = temp;
	}
	return numArr;
}

void OperatorFrenzy::fillOperatorQueue(char operArr[], bool used[]) {
	//The loop will not end until the entire queue of operators is filled
	while ((signed)operQueue.size() < queueCapacity) {
		std::string choice;
		std::cout << "\nType the next number for the operator you want to place next.\n";
		std::cin >> choice;
		system("CLS");

		compareChoice(choice);

		if (choice != "help" && choice != "set") {
			//Checks user-input string
			for (unsigned int i = 0; i < choice.length(); i++) {
				//If it is alphanumeric, alphabetical, or full of symbols, it will not process
				if (!isdigit(choice[i])) {
					std::cout << "The choice is not a positive number.\n";
					break;
				}
				//On the last character (if successfully passing the previous steps), the string is converted into an integer
				if (i == choice.length() - 1) {
					int newChoice = std::stoi(choice);

					//The number is then checked if it has been previously used, or if the capacity is outside of the intended range
					if (newChoice > 0 && newChoice <= queueCapacity && !used[newChoice - 1]) {
						operQueue.push(operArr[newChoice - 1]);
						used[newChoice - 1] = true;
					}

					else {
						std::cout << "The value does not fit with the given capacity or is already in use.\n";
					}
				}
			}
		}
		//* To be implemented *
		else if (choice == "set") {

		}

		//Displays the remaining items in the operator array
		std::cout << "The current operator choices left are: ";
		for (int i = 0; i < queueCapacity; i++)
		{
			//Displays only operator symbols that have an index not already specified
			if (!used[i])
				std::cout << "(" << i + 1 << ") " << operArr[i] << "\t";
		}
		std::cout << std::endl;
	}
}
int OperatorFrenzy::pullFromQueue(int startAmt, int numArr[])
{
	FrenzyUtil t1(startAmt);
	int idx = 0;
	int amt;

	while (!operQueue.empty()) {

		FrenzyUtil t2(numArr[idx++]);

		switch (operQueue.front())
		{
			case '+': {
				amt = t1 + t2;
				break;
			}
			case '-': {
				amt = t1 - t2;
				break;
			}
			case '*': {
				amt = t1 * t2;
				break;
			}
		}

		t1.setVal(amt);
		std::cout << amt << std::endl;

		operQueue.pop();
	}
	return amt;
}