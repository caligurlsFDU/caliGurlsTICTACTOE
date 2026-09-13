#include <iostream>
#include <string>

using namespace std;

int userChoice;
bool returnToMainMenu = true;

int main()
{
	while(returnToMainMenu)
	{
	cout << "Welcome to Tic Tac Toe. Please select an option with the cooresponding num key\n";
	cout << "1: Play\n";
	cout << "2: Instructions\n";
	cout << "3: Exit\n";
	cout << "4: Display sample board\n";

	cin >> userChoice;

	switch (userChoice) //switch statement with all 4 (three but the fourth is temporary) options. Option 3 exits the loop with a goodbye message.
	{
	case 1:
		cout << "\nPlay selected.";
		break;

	case 2:
		cout << "\nInstructions.";
		break;

	case 3:
		cout << "\nExiting program.";
		returnToMainMenu = false;
		break;

	case 4:
		cout << "\nDisplaying sample board:";
		cout << "\n \n \n";
		cout << "O X O\n";
		cout << "X O X\n";
		cout << "O X O\n";
		break;

	default:
		cout << "\nInvalid input. Returning to menu\n";
		break;
	}

	}

	cout << "\nGoodbye!";
}