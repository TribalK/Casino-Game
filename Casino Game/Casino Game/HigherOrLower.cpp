#include "HigherOrLower.h"

//Considering implementing double or nothing system
//Constructor
HigherOrLower::HigherOrLower(Player &patron)
{
	//updating player's cash for game payment entry
	patron.updateCash();

	//checks instruction flag
	std::string playerChoice;
	if (Casino::checkFlags(gameID)) {
		Help();
		Casino::updateFlags(gameID);
	}

	//Calls random function to generate a number between 1 and 95
	int predictor = random(1, 19) * 5;
	int total;
	int currScore;

	//Another number is called to compare against the 'predictor'
	int compRandNum = random(1, 99);

	//Prompting user input
	do
	{
		std::cout << "Is the number higher or lower than " << predictor << "? Type your answer below.\n";
		std::cin >> playerChoice;

		//compare method to determine input string validity.
		compareChoice(playerChoice);

		//invalid result display
	} while (playerChoice == "help" || (playerChoice != "lower" && playerChoice != "higher"));

	//comparing valid results
	if ((playerChoice == "lower" && compRandNum < predictor) || (playerChoice == "higher" && compRandNum > predictor)) {
		std::cout << "You win! The number was " << compRandNum << std::endl;
		total = 10;
		currScore = 100;
	}
	//On the rare chance that both the predictor and comparator number are the same
	//(where nothing could have been done on the player's end, they are rewarded
	else if (compRandNum == predictor) {
		std::cout << "Wow! The result and the predictor were both the same number! You win a lucky bonus!\n";
		total = 40;
		currScore = 200;
	}
	else {
		std::cout << "Sorry, you lost. The number was " << compRandNum << std::endl;
		total = 0;
		currScore = 0;
	}

	//Set player's score and earning data based on results
	patron.setCurrentEarnings(total);
	patron.setCurrentScore(currScore);
	patron.updateCash();
	patron.updateScore();
}

/******************************************
Help function that displays text of
instructions for the player when they are
stuck. This displays on the first entry into
the game, afterward it must be called with
user string input "Help" during input prompt
in order to display afterwards.
*******************************************/
void HigherOrLower::Help()
{
	std::cout << "Here's how Higher or Lower works. The computer will randomly generate a number between 1 and 100.\n";
	std::cout << "There will also be a predictor randomly generated that is divisible by 5.\n";
	std::cout << "Given the predictor, you must simply guess if the answer is going to be less than or greater than the predictor.\n";
	std::cout << "You can either say \"Higher\" or \"Lower\" (without quotation marks) for each guess.\n";
	std::cout << "You will earn points and money if you guess correctly, and will lose money if you guess incorrectly.\n";
	std::cout << "If the two randomly generated numbers end up being the same, you will be rewarded a large bonus!\n";
	std::cout << "Ready to play? You can type \"Help\" as your input response if you need instructions repeated at any time.\n\n";
}

/******************************************
Function to format string input, decides
whether it is a valid input given a few
select choices. If it is not valid, it will
reforce the player to enter another string.
*******************************************/
std::string HigherOrLower::compareChoice(std::string& choice)
{
	//Convert input string to lowercase
	std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		Help();

	else if (choice.compare("lower") != 0 && choice.compare("higher") != 0) {
		std::cout << "You entered an incorrect prompt. Please try entering either \"Lower\", \"Higher\", or \"Help\". \n\n";
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return choice;
}