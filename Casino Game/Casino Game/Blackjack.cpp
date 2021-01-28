#include "Casino.h"

//Constructor
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
	
	playerCards.push_back(deck.back());
	deck.pop_back();

	playerCards.push_back(deck.back());
	deck.pop_back();

	dealerCards.push_back(deck.back());
	deck.pop_back();

	dealerCards.push_back(deck.back());
	deck.pop_back();

	displayDecks(playerCards, dealerCards, playerCards.size(), dealerCards.size());
	player_sum = evaluateDeck(playerCards);
	dealer_sum = evaluateDeck(dealerCards);

	if (player_sum == 21) {
		cout << "What a lucky draw! You got blackjack!\n";
		patron.setCurrentEarnings(50);
		patron.setCurrentScore(500);
		patron.updateCash();
		patron.updateScore();
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
			displayDecks(playerCards, dealerCards, playerCards.size(), dealerCards.size());
			cout << "Current score: " << player_sum << endl;
			
		}

	} while ((choice != "stay") && (player_sum < 21));

	hiddenFlag = false;
	cout << "The dealer has revealed his down card to be: " << dealerCards.at(0) << endl;

	while (dealer_sum < 17)
	{
		dealerCards.push_back(deck.back());
		deck.pop_back();
		dealer_sum = evaluateDeck(dealerCards);
	}

	displayDecks(playerCards, dealerCards, playerCards.size(), dealerCards.size());

	cout << "You have " << player_sum << " points.\n";
	cout << "The dealer has " << dealer_sum << " points.\n";

	int total = determineWinner(player_sum, dealer_sum);

	patron.setCurrentEarnings(total);
	patron.setCurrentScore(total * 10);
	patron.updateCash();
	patron.updateScore();

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
	cout << "Here's how Blackjack works. You will receive two cards from the dealer, face-up.\n" <<
		"The dealer will then give themselves two cards, one face-down and the other face up.\n" <<
		"Your job is to continue picking up cards by saying 'Hit' until you have either broke\n" <<
		"the score of 21 or you choose to 'Stay'. The dealer will then continue to hit until\n" <<
		"they have reached a score of 17 or higher. If the player breaks, the dealer will win by default.\n" <<
		"If both the player and the dealer are under or within the threshold of 21, the highest score wins.\n\n";
}

int Blackjack::evaluateDeck(vector<int> cards)
{
	int total = 0;
	int aceCounter = 0;
	int deckSize = cards.size();

	for (int i = 0; i < deckSize; i++)
	{
		if (cards.at(i) == Ace)
			aceCounter++;

		total += cards.at(i);
	}

	total = determineBestAces(aceCounter, total);

	return total;
}

string Blackjack::BjCompare(string& choice)
{
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	if (choice.compare("help") == 0)
		BlackjackHelp();

	else if (choice.compare("hit") != 0 && choice.compare("stay") != 0) {
		cout << "You entered an incorrect prompt. Please try entering either \"Hit\", \"Stay\", or \"Help\". \n\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return choice;
}

void Blackjack::displayDecks(vector<int> playerDeck, vector<int> dealerDeck, int pDeckSize, int dDeckSize)
{
	cout << "Player's deck: \n";
	for (int i = 0; i < pDeckSize; i++)
	{
		cout << playerDeck.at(i) << " ";
	}

	cout << endl << endl;
	cout << "Dealer's deck: \n";

	//Replacing first character of dealer's deck
	if (hiddenFlag)
		cout << "X ";
	else
		cout << dealerDeck.at(0) << " ";

	for (int i = 1; i < dDeckSize; i++)
	{
		cout << dealerDeck.at(i) << " ";
	}

	cout << endl << endl;
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

int Blackjack::determineWinner(int player_sum, int dealer_sum)
{
	if (player_sum > 21) {
		cout << "You broke! The dealer wins!\n";
		return 0;
	}

	else if (player_sum <= 21 && dealer_sum > 21) {
		cout << "The dealer broke! You win!\n";
		return 30;
	}

	else {
		if (player_sum < dealer_sum) {
			cout << "The dealer wins!\n";
			return 0;
		}

		else if (player_sum > dealer_sum) {
			cout << "You win!\n";
			return 50;
		}
		else {
			cout << "You and the dealer tied! You get your original amount back.\n";
			return 10;
		}
	}
}