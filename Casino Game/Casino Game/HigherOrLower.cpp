#include "Casino.h"

//Considering implementing double or nothing system
HigherOrLower::HigherOrLower(Player &patron)
{
	patron.updateCash();

	string playerChoice;
	if (patron.checkFlags(gameID)) {
		HoLHelp();
		patron.updateFlags(gameID);
	}

	int predictor = random(1, 19) * 5;
	int total;
	int currScore;
	compRandNum = random(1, 99);

	do
	{
		cout << "Is the number higher or lower than " << predictor << "? Type your answer below.\n";
		cin >> playerChoice;

		HoLCompare(playerChoice);

	} while (playerChoice == "help" || (playerChoice != "lower" && playerChoice != "higher"));

	if ((playerChoice == "lower" && compRandNum < predictor) || (playerChoice == "higher" && compRandNum > predictor)) {
		cout << "You win! The number was " << compRandNum << endl;
		total = 20;
		currScore = 100;
	}
	else if (compRandNum == predictor) {
		cout << "Wow! The result and the predictor were both the same number! You win a lucky bonus!\n";
		total = 40;
		currScore = 200;
	}
	else {
		cout << "Sorry, you lost. The number was " << compRandNum << endl;
		total = 0;
		currScore = 0;
	}

	patron.setCurrentEarnings(total);
	patron.setCurrentScore(currScore);
	patron.updateCash();
	patron.updateScore();
}

void HigherOrLower::HoLHelp()
{
	cout << "Here's how Higher or Lower works. The computer will randomly generate a number between 1 and 100.\n";
	cout << "There will also be a predictor randomly generated in that is divisible by 5.\n";
	cout << "Given the predictor, you must simply guess if the answer is going to be less than or greater than the predictor.\n";
	cout << "You can either say \"Higher\" or \"Lower\" (without quotation marks) for each guess.\n";
	cout << "You will earn points and money if you guess correctly, and will lose money if you guess incorrectly.\n";
	cout << "If the two randomly generated numbers end up being the same, you will be rewarded a large bonus!\n";
	cout << "Ready to play? You can type \"Help\" as your input response if you need instructions repeated at any time.\n\n";
}

string HigherOrLower::HoLCompare(string& choice)
{
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		HoLHelp();

	else if (choice.compare("lower") != 0 && choice.compare("higher") != 0) {
		cout << "You entered an incorrect prompt. Please try entering either \"Lower\", \"Higher\", or \"Help\". \n\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return choice;
}