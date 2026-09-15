#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int userChoice;
bool returnToMainMenu = true;
//bool for loop control and global int to let user make inputs

void printBoard(int boardState[]);
void changeBoard(int boardState[]);
//function declaration for two functions used later

int main()
{
	srand(time(NULL));
	int randomNumber = (rand() % 9 + 1); //not implemented yet but generates a random number between 1 and 9 for the cpu to pick
	int ticTacToe[9] = { 0,1,2,0,1,2,0,1,2 }; //edit this before selecting option 4 in the menu to test different board layouts.
	bool gameRunning = true; 
	bool playerChose = false; //both of these are misc bools used to control loops

	while(returnToMainMenu)
	{
	cout << "Welcome to Tic Tac Toe. Please select an option with the cooresponding num key\n";
	cout << "1: Play\n";
	cout << "2: Instructions\n";
	cout << "3: Exit\n";
	cout << "4: Display sample board\n";

	cin >> userChoice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		goto failed;
	}

	switch (userChoice) //switch statement with all 4 (three but the fourth is temporary) options. Option 3 exits the loop with a goodbye message.
	{
	case 1:
		gameRunning = true;
		cout << "\nPlay selected.";
		while (gameRunning)
		{

		}
		break;

	case 2:
		cout << "\nInstructions:\n";
		cout << "Get three of your symbol (X) in a row while blocking your opponent to win! Input your moves by selecting the cooresponding grid space\n";
		cout << "1 2 3\n4 5 6\n7 8 9\n";
		break;

	case 3:
		cout << "\nExiting program.";
		returnToMainMenu = false;
		break;

	case 4:
		cout << "\nDisplaying sample board:\n";
		printBoard(ticTacToe);
		break;


	failed:
	default:
		cout << "\nInvalid input. Returning to menu\n";
		break;
	}

	}

	cout << "\nGoodbye!";
}

void changeBoard(int boardState[])
{
	bool playerChose = false;

	cout << "Player, select the space ";
	while (playerChose = false)
	{

	}
}

void printBoard(int boardState[])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch(boardState[i * 3 + j])
			{
			case 0:
				cout << "?";
				break;

			case 1:
				cout << "X";
				break;
				
			case 2:
				cout << "O";
				break;

			default:
				cout << "you shouldn't see this";
			}

			cout << " ";
		}

		cout << "\n";
	}

}