#include "HigherOrLower.h"
#include "Blackjack.h"
#include "OperatorFrenzy.h"
#include "SaveData.h"

void IntroText();
void PlayGames(Player patron);

//Implement Class for Player
//Potential score/money save and load system? I/O to text file
//Initialize player name and initial money/score count in constructor
//Boolean to declare bankruptcy
//Prompts user to choose a higher or lower number each round than the randomized range
//If answer is in the correct range, they earn money
//If they guess incorrectly, they lose money
//No money = Game Over

//System("CLS") and System("pause") functions not suitable on other OS's, may look for alternatives
//resolved System("pause")

int main()
{
	srand((unsigned)time(NULL));
	IntroText();
	system("CLS");

	std::string name;
	std::cout << "Enter the name or username you would like to go by.\n";
	std::cin >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << std::endl << "Alright, " << name << "! Setting you up now. You will be given a starting cash amount of $30.\n";
	std::cout << "Try not to lose it all.\n";

	Player patron(name);
	PlayGames(patron);

	return 0;
}

void IntroText()
{
	std::string str;
	str.assign(110, '=');

	std::cout << str << std::endl;

	for (int i = 0; i <= 11; i++)
	{
		std::cout << "\t$";
	}

	std::cout << std::endl << str << std::endl;
	std::cout << "\t  # # # #           #             # # # #      # # # #     # #     # #       # # # # #\n";
	std::cout << "\t #  # # # #      #     #        #         #     #   #     #   #   #   #    #           #\n";
	std::cout << "\t#  #           #    #    #      #     # # #     #   #     #    #  #   #   #             #\n";
	std::cout << "\t#  #          #    # #    #       #    #        #   #     #     # #   #   #    # # #    #\n";
	std::cout << "\t#  #          #   # # #   #         #    #      #   #     #           #   #   #     #   #\n";
	std::cout << "\t#  #          #           #           #   #     #   #     #   # #     #   #    # # #    #\n";
	std::cout << "\t#  #          #   # # #   #      # # #     #    #   #     #   #  #    #   #             #\n";
	std::cout << "\t #  # # # #   #   #   #   #     #        #      #   #     #   #   #   #    #           #\n";
	std::cout << "\t  # # # #     # # #   # # #      # # # #       # # # #     # #     # #       # # # # # \n";
	std::cout << str << std::endl;

	for (int i = 0; i <= 11; i++)
	{
		std::cout << "\t$";
	}

	std::cout << std::endl << str << std::endl << std::endl;

	std::cout << "Press Enter to continue.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PlayGames(Player patron)
{
	while (!patron.isBankrupt())
	{
		int choice = patron.getPlayerChoice();
		system("CLS");

		switch (choice)
		{
		case CHOICE_1: {
			std::cout << "You selected: Play Higher or Lower\n\n";
			HigherOrLower C1(patron);
			break;
		}
		case CHOICE_2: {
			std::cout << "You selected: Play Blackjack\n\n";
			Blackjack C2(patron);
			break;
		}
		case CHOICE_3: {
			std::cout << "You selected: Operator Frenzy\n\n";
			OperatorFrenzy C3(patron);
			break;
		}
		case CHOICE_4: {
			std::cout << "You selected: Save score data.\n\n";
			SaveData C4(patron);
			break;
		}
		case CHOICE_5: {
			std::cout << "You chose to quit. Thank you for playing!\n";
			exit(1);
			break;
		}
		case -1: {
			break;
		}
		default: {
			std::cout << "Not a valid choice.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		}
	}
	std::cout << "\nYou have ran out of money. Please leave the Casino.\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}