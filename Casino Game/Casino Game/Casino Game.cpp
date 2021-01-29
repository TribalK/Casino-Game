#include "Casino.h"

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
	/*Testing for current working directory
	char* buffer;

	// Get the current working directory:
	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else
	{
		//printf("%s \nLength: %zu\n", buffer, strlen(buffer));
		cout << buffer << ": Length " << strlen(buffer) << endl;
		free(buffer);
	}*/

	srand((unsigned)time(NULL));
	IntroText();
	system("CLS");

	string name;
	cout << "Enter the name you would like to go by.\n";
	cin >> name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl << "Alright, " << name << "! Setting you up now. You will be given a starting cash amount of $50.\n";
	cout << "Try not to lose it all.\n";

	Player patron(name);
	PlayGames(patron);

	return 0;
}

void IntroText()
{
	string str;
	str.assign(110, '=');

	cout << str << endl;

	for (int i = 0; i <= 11; i++)
	{
		cout << "\t$";
	}

	cout << endl << str << endl;
	cout << "\t  # # # #           #             # # # #      # # # #     # #     # #       # # # # #\n";
	cout << "\t #  # # # #      #     #        #         #     #   #     #   #   #   #    #           #\n";
	cout << "\t#  #           #    #    #      #     # # #     #   #     #    #  #   #   #             #\n";
	cout << "\t#  #          #    # #    #       #    #        #   #     #     # #   #   #    # # #    #\n";
	cout << "\t#  #          #   # # #   #         #    #      #   #     #           #   #   #     #   #\n";
	cout << "\t#  #          #           #           #   #     #   #     #   # #     #   #    # # #    #\n";
	cout << "\t#  #          #   # # #   #      # # #     #    #   #     #   #  #    #   #             #\n";
	cout << "\t #  # # # #   #   #   #   #     #        #      #   #     #   #   #   #    #           #\n";
	cout << "\t  # # # #     # # #   # # #      # # # #       # # # #     # #     # #       # # # # # \n";
	cout << str << endl;

	for (int i = 0; i <= 11; i++)
	{
		cout << "\t$";
	}

	cout << endl << str << endl << endl;

	cout << "Press Enter to continue.\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void PlayGames(Player patron)
{
	patron.initializeFlags();
	while (!patron.isBankrupt())
	{
		//patron.displayFlags();
		int choice = patron.getPlayerChoice();
		system("CLS");

		switch (choice)
		{
		case CHOICE_1: {
			cout << "You selected: Play Higher or Lower\n\n";
			HigherOrLower C1(patron);
			break;
		}
		case CHOICE_2: {
			cout << "You selected: Play Blackjack\n\n";
			Blackjack C2(patron);
			break;
		}
		case CHOICE_3: {
			cout << "You selected: Save score data.\n\n";
			SaveData C3(patron);
			break;
		}
		case CHOICE_4: {
			cout << "You chose to quit. Thank you for playing!\n\n";
			exit(1);
			break;
		}
		default: {
			cout << "Not a valid choice.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		}
	}
	cout << "You have ran out of money. Please leave the Casino.\n";
}