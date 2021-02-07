#pragma once
#include "Player.h"
#include <vector>

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
	std::vector<int> deck;
	std::vector<int> playerCards;
	std::vector<int> dealerCards;
	int King = 10;
	int Queen = 10;
	int Jack = 10;
	int Ace = 1;
	const int gameID = CHOICE_2 - 1;
	bool hiddenFlag = true;
public:
	Blackjack(Player &patron);
	void create_deck();
	void shuffle_deck(int n);
	void BlackjackHelp();
	std::string BjCompare(std::string& choice);
	void displayDecks(std::vector<int> playerDeck, std::vector<int> dealerDeck, int pDeckSize, int dDeckSize);
	int determineBestAces(int n, int total);
	int evaluateDeck(std::vector<int> playerCards);
	int determineWinner(int player_sum, int dealer_sum);
};