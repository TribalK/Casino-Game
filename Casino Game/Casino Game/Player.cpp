#include "Casino.h"

//Constructor
Player::Player(string name)
{
	this->playerName = name;
	this->playerScore = 0;
	this->playerCash = 50;
}

int Player::getPlayerChoice()
{
	int number;

	cout << "----------------------------------------------------------------------------\n";
	cout << "Select which game or option you would like to select by choosing the number:\n\n";
	cout << "1. Higher or Lower ($10 to play).\n";
	cout << "2. Blackjack ($10 to play).\n";
	cout << "3. Save score.\n";
	cout << "4. Quit.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	
	cin >> number;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
	cout << "You have a score of: " << playerScore + getCurrentScore() << endl;
	return playerScore += getCurrentScore();
}

void Player::displayCurrentData()
{
	cout << "   Player: " << playerName << endl;
	cout << "   Score: " << playerScore << endl;
	cout << "   Cash:  $" << playerCash << endl;

	setCurrentEarnings(playerCash);
	setCurrentScore(playerScore);
}

string Player::getName()
{
	return playerName;
}

bool Player::isBankrupt()
{
	return playerCash <= 0;
}

void Casino::initializeFlags()
{
	for (int i = 0; i < 3; i++) {
		instructFlags[i] = true;
	}
}

bool Casino::checkFlags(int ID)
{
	return instructFlags[ID];
}

void Casino::updateFlags(int ID)
{
	instructFlags[ID] = false;
}

void Casino::displayFlags()
{
	for (int i = 0; i < 3; i++)
		cout << i << ": " << instructFlags[i] << endl;
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