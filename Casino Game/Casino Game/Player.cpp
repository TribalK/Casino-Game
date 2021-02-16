#include "Player.h"

//Constructor
Player::Player(std::string name)
{
	this->playerName = name;
	this->playerScore = 0;
	this->playerCash = 50;
}

int Player::getPlayerChoice()
{
	int number;

	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "Select which game or option you would like to select by choosing the number:\n\n";
	std::cout << "1. Higher or Lower ($5 to play).\n";
	std::cout << "2. Blackjack ($10 to play).\n";
	std::cout << "3. Operator Frenzy ($30 to play).\n";
	std::cout << "4. Save score.\n";
	std::cout << "5. Quit.\n";
	std::cout << "----------------------------------------------------------------------------\n\n";
	
	std::cin >> number;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (number == 1)
		setCurrentEarnings(-5);

	else if (number == 2) {
		if (playerCash < 10) {
			number = insufficentFunds("Blackjack");
		}
		else
			setCurrentEarnings(-10);
	}

	else if (number == 3) {
		if (playerCash < 30) {
			number = insufficentFunds("Operator Frenzy");
		}
		else
			setCurrentEarnings(-30);
	}

	return number;
}

int Player::updateCash()
{
	return playerCash += getCurrentEarnings();
}

int Player::updateScore()
{
	std::cout << "You have a score of: " << playerScore + getCurrentScore() << std::endl;
	return playerScore += getCurrentScore();
}

void Player::displayCurrentData()
{
	std::cout << "   Player: " << playerName << std::endl;
	std::cout << "   Score: " << playerScore << std::endl;
	std::cout << "   Cash:  $" << playerCash << std::endl;

	setCurrentEarnings(playerCash);
	setCurrentScore(playerScore);
}

std::string Player::getName()
{
	return playerName;
}

bool Player::isBankrupt()
{
	return playerCash <= 0;
}

void Player::setCurrentEarnings(int amount)
{
	current_earnings = amount;
}

int Player::getCurrentEarnings()
{
	return current_earnings;
}

void Player::setCurrentScore(int score)
{
	current_score = score;
}

int Player::getCurrentScore()
{
	return current_score;
}

int Player::insufficentFunds(std::string optName)
{
	std::cout << "Insufficient funds. Unable to play " << optName << " right now.\n";
	std::cout << "You currently only have " << playerCash << " dollars.\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return -1;
}