/************************************************
Casino.h

Header file that contains libraries and
class structures for the entire Casino program.

************************************************/

#pragma once
//Include libraries
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <direct.h>
#include <cstdlib>

//May replace all std with cout::std and cout::endl, etc
using namespace std;

const int CHOICE_1 = 1;
const int CHOICE_2 = 2;
const int CHOICE_3 = 3;
const int CHOICE_4 = 4;

//Classes:

/***********************************************
Casino Class

Used to determine information set by the Player
class. Whenever a game is played by the player,
money, a current value is set for updating. The
getter and setter functions are utilized whenever
we need to update the player's cash (and score)
values.

The flag functions are utilized to display each
option's help information a single time unless
requested by the user otherwise.

***********************************************/
class Casino
{
private:
	bool instructFlags[3];
public:
	void initializeFlags();
	bool checkFlags(int ID);
	void updateFlags(int ID);
	void displayFlags();
};

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
	string playerName;
	int playerCash;
	int playerScore;
	int current_earnings;
	int current_score;
public:
	Player() {};
	Player(string name);
	Player(string name, int cash, int score);
	int updateCash();
	int updateScore();
	int getPlayerChoice();
	void setCurrentEarnings(int amount);
	int getCurrentEarnings();
	void setCurrentScore(int score);
	int getCurrentScore();
	string getName();
	void displayCurrentData();
	bool isBankrupt();
};

/***********************************************
HigherOrLower class

Game to guess a number given a predictor and
the computer's true value

***********************************************/
class HigherOrLower : public Player
{
private:
	int compRandNum;
	const int gameID = CHOICE_1 - 1;
public:
	HigherOrLower(Player &patron);
	string HoLCompare(string& choice);
	void HoLHelp();
	int random(int i, int n) { return rand() % n + i; }
};

/***********************************************
Blackjack class

Game to play Blackjack against the dealer, both
groups take cards from a shuffle deck, and their
totals are compared to one another.

If the player's total breaks the max value of 21,
they lose the game.

***********************************************/
class Blackjack : public Player
{
private:
	vector<int> deck;
	vector<int> playerCards;
	vector<int> dealerCards;
	int King = 10;
	int Queen = 10;
	int Jack = 10;
	int Ace = 1;
	int dealer_sum = 0;
	int player_sum = 0;
	const int gameID = CHOICE_2 - 1;
	bool hiddenFlag = true;
public:
	Blackjack(Player &patron);
	void create_deck();
	void shuffle_deck(int n);
	void BlackjackHelp();
	string BjCompare(string& choice);
	void displayDecks(vector<int> playerDeck, vector<int> dealerDeck, int pDeckSize, int dDeckSize);
	int determineBestAces(int n, int total);
	int evaluateDeck(vector<int> playerCards);
	int determineWinner(int player_sum, int dealer_sum);
};

//Work in progress - save function
//Save to IO file
class SaveData : public Player
{
private:
	const int gameID = CHOICE_3 - 1;
public:
	SaveData(Player &patron);
	void SDCompare();
	void SDHelp();
};