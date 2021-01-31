#pragma once
#include "Casino.h"

/***********************************************
Player Class

The player has values for cash and score (in
progress) values that will update whenever a game
is played, and the results of the game is determined.

If the player gets to a point where they run out
of money, they will no longer be allowed to play
any games in the Casino. (determined by boolean function)

***********************************************/
class Player : public Casino
{
private:
	std::string playerName;
	int playerCash;
	int playerScore;
	int current_earnings;
	int current_score;
public:
	Player() {};
	Player(std::string name);
	Player(std::string name, int cash, int score);
	int updateCash();
	int updateScore();
	int getPlayerChoice();
	void setCurrentEarnings(int amount);
	int getCurrentEarnings();
	void setCurrentScore(int score);
	int getCurrentScore();
	std::string getName();
	void displayCurrentData();
	bool isBankrupt();
};
