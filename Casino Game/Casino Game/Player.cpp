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
	std::cout << "1. Higher or Lower ($10 to play).\n";
	std::cout << "2. Blackjack ($10 to play).\n";
	std::cout << "3. Save score.\n";
	std::cout << "4. Quit.\n";
	std::cout << "----------------------------------------------------------------------------\n\n";
	
	std::cin >> number;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (number > 0 && number <= 2)
		setCurrentEarnings(-10);

	return number;
}

int Player::updateCash()
{
	//cout << "You had: $" << playerCash << " dollars, added with current earnings in: " << getCurrentEarnings() << endl;
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