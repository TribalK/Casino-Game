#include "Casino.h"

Blackjack::Blackjack(Player &patron)
{
	string choice;
	patron.updateCash();

	if (patron.checkFlags(gameID)) {
		BlackjackHelp();
		patron.updateFlags(gameID);
	}

	create_deck();
	shuffle_deck(deck.size());
	/*int next_line = 1;

	for(size_t i = 0; i < deck.size(); i++)
	{
		cout << deck[i] << " ";
		if(next_line % 10 == 0)
		{
			cout << endl;
		}
		next_line++;
	}
	cout << endl;*/

	playerCards.push_back(deck.back());
	deck.pop_back();

	playerCards.push_back(deck.back());
	deck.pop_back();

	dealerCards.push_back(deck.back());
	deck.pop_back();

	dealerCards.push_back(deck.back());
	deck.pop_back();

	player_sum = evaluateDeck(playerCards);
	dealer_sum = evaluateDeck(dealerCards);

	if (player_sum == 21) {
		patron.setCurrentEarnings(50);
		patron.updateCash();
		return;
	}

	do
	{
		cout << "Would you like to Hit or Stay?\n";
		cin >> choice;
		BjCompare(choice);

		if (choice == "hit")
		{
			playerCards.push_back(deck.back());
			deck.pop_back();
			player_sum = evaluateDeck(playerCards);

			cout << "Current score: " << player_sum << endl;
		}

	} while ((choice != "stay") && (player_sum < 21));

	while (dealer_sum < 17)
	{
		dealerCards.push_back(deck.back());
		deck.pop_back();
		dealer_sum = evaluateDeck(dealerCards);
	}

	cout << "You have " << player_sum << " points.\n";
	cout << "The dealer has " << dealer_sum << " points.\n";


}
void Blackjack::create_deck()
{
	deck = { Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King,
			Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King,
			Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King,
			Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King };
}

void Blackjack::shuffle_deck(int n)
{
	for (int i = 0; i < n; i++)
	{
		int r = i + (rand() % (52 - i));
		swap(deck[i], deck[r]);
	}
}

void Blackjack::BlackjackHelp()
{
	cout << "Here's how Blackjack works. You will receive two cards from the dealer, face-up.\n " <<
		"The dealer will then give themselves two cards, one face-down and the other face up.\n";
}

int Blackjack::evaluateDeck(vector<int> cards)
{
	int total = 0;
	int aceCounter = 0;
	int deckSize = cards.size();

	cout << "You have: \n";

	for (int i = 0; i < deckSize; i++)
	{
		if (cards.at(i) == Ace)
			aceCounter++;

		cout << cards.at(i) << " ";

		total += cards.at(i);
	}

	cout << endl;
	//cout << "There are " << aceCounter << " aces in the deck\n\n";
	total = determineBestAces(aceCounter, total);

	//cout << "total is: " << total << endl;
	return total;
}

string Blackjack::BjCompare(string& choice)
{
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		BlackjackHelp();

	else if (choice.compare("hit") != 0 && choice.compare("stay") != 0) {
		cout << "You entered an incorrect prompt. Please try entering either \"Hit\", \"Stay\", or \"Help\". \n\n";
	}

	return choice;
}

int Blackjack::determineBestAces(int n, int total)
{
	if (n == 0)
		return total;

	else if ((n * 10) + total <= 21) {
		return ((n * 10) + total);
	}

	else {
		return determineBestAces(n - 1, total);
	}

}