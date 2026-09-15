#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int userChoice;
bool returnToMainMenu = true;
//bool for loop control and global int to let user make inputs

void printBoard(int boardState[]);
void playerChange(int boardState[]);
bool checkWin(int boardState[]);
void computerChange(int boardState[]);
//function declaration for two functions used later

int main()
{
	srand(time(NULL));
	int randomNumber = (rand() % 9 + 1); //not implemented yet but generates a random number between 1 and 9 for the cpu to pick
	int ticTacToe[9] = { 0,0,0,0,0,0,0,0,0 }; //edit this before selecting option 4 in the menu to test different board layouts.
	bool gameRunning = true; 
	bool playerChose = false; //both of these are misc bools used to control loops
	bool playerWins = false;
	bool CPUWins = false;

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
			cout << "Player (X)'s turn\n";
			cout << "\n\n";
			playerChange(ticTacToe);
			playerWins = checkWin(ticTacToe);
			printBoard(ticTacToe);
			if (playerWins)
			{
				cout << "\n\n\nPlayer (X) wins!\n\n\n";
				gameRunning = false;
				break;
			}
			cout << "\n\n";
			cout << "CPU (O's) turn\n";
			computerChange(ticTacToe);
			CPUWins = checkWin(ticTacToe);
			printBoard(ticTacToe);
			if (CPUWins)
			{
				cout << "\n\n\nCPU (O) wins!\n\n\n";
				gameRunning = false;
				break;
			}

			}
		
		for (int i = 0; i < 9; i++)
			{
				ticTacToe[i] = 0;
			}
		//wipe the tic tac toe board so user can play again

		break;

	case 2:
		cout << "\nInstructions:\n";
		cout << "Get three of your symbol (X) in a horizontal, vertical, or diagonal row while blocking your opponent to win! Input your moves by selecting the cooresponding grid space\n";
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

bool checkWin(int boardState[])
{
	if ((boardState[0] != 0 && boardState[0] == boardState[1] && boardState[1] == boardState[2]) || (boardState[3] != 0 && boardState[3] == boardState[4] && boardState[4] == boardState[5]) ||	(boardState[6] != 0 && boardState[6] == boardState[7] && boardState[7] == boardState[8]))
	{
		//massive line above checks all three horizontals
		return true;
	}
	else if ((boardState[0] != 0 && boardState[0] == boardState[3] && boardState[3] == boardState[6]) || (boardState[1] != 0 && boardState[1] == boardState[4] && boardState[4] == boardState[7]) || (boardState[2] != 0 && boardState[2] == boardState[5] && boardState[5] == boardState[8]))
	{
		//massive line above checks all three verticals
		return true;
	}
	else if ((boardState[0] != 0 && boardState[0] == boardState[4] && boardState[4] == boardState[8]) || (boardState[2] != 0 && boardState[2] == boardState[4] && boardState[4] == boardState[6]))
	{
		//slightly less massive line checks diagonals;
		return true;
	}
	else
	{
		return false;
	}
	
}

void playerChange(int boardState[])
{
	bool playerChose = false;
	int choice = 777;
	while (playerChose == false)
	{
		playerFailed:
		cout << "Player, select move (1-9)\n";
		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Input not valid\n";
			goto playerFailed;
		}

		choice--;

		if (boardState[choice] != 0)
		{
			cout << "invalid move. space is occupied. select again.";
		}
		else
		{
			boardState[choice] = 1;
			playerChose = true;
		}
	}
}

void computerChange(int boardState[])
{
	bool CPUChose = false;
	int choice = (rand() % 9 + 1);
	
	while (CPUChose == false)
	{
		choice--;
		if (boardState[choice] != 0)
		{
			choice = (rand() % 9 + 1);
		}
		else
		{
			boardState[choice] = 2;
			CPUChose = true;
		}
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