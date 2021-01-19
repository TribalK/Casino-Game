/************************************************
Casino.h




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
#include <cstdlib>

using namespace std;

const int CHOICE_1 = 1;
const int CHOICE_2 = 2;
const int CHOICE_3 = 3;
const int CHOICE_4 = 4;

class Casino
{
private:
	bool instructFlags[3];
	int current_earnings;
public:
	int random(int i, int n) { return rand() % n + i; }
	void initializeFlags();
	bool checkFlags(int ID);
	void updateFlags(int ID);
	void displayFlags();
	void setCurrentEarnings(int amount);
	int getCurrentEarnings();
	virtual int results() { return 0; };
};

class Player : public Casino
{
private:
	string playerName;
	int playerCash;
	int playerScore;
public:
	Player(string name);
	Player(string name, int cash, int score);
	int updateCash();
	int getPlayerChoice();
	bool isBankrupt();
};

class HigherOrLower : public Casino
{
private:
	int compRandNum;
	int total;
	const int gameID = CHOICE_1 - 1;
public:
	HigherOrLower(Player &patron);
	string HoLCompare(string& choice);
	void HoLHelp();
};

class Blackjack : public Casino
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
public:
	Blackjack(Player &patron);
	void create_deck();
	void shuffle_deck(int n);
	void BlackjackHelp();
	string BjCompare(string& choice);
	int determineBestAces(int n, int total);
	int determineWinner(int player_sum, int dealer_sum);
	int evaluateDeck(vector<int> playerCards);
};