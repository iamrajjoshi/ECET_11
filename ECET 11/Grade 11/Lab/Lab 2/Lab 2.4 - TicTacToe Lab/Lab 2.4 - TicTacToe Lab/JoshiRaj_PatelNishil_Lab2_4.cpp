//Lab 2_4
//Raj Joshi & Nishil Patel
//Written by Nishil Patel

#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
	const char x = 'x';
	const char o = 'o';
	char board[3][3];

public:
	TicTacToe();
	bool endgame();
	bool move(int, int);;
	bool player = false;
	void display();

};

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
}

bool TicTacToe::move(int row, int col)
{

	if (row > 0 && row < 4 && col > 0 && col < 4)
	{
		if (board[row - 1][col - 1] != ' ')
		{
			return false;
		}
		else if (player)
		{
			board[row - 1][col - 1] = x;
			cout << player << endl;
		}
		else
			board[row - 1][col - 1] = o;
		return true;
	}

	return false;
}

bool TicTacToe::endgame()
{

	if (board[0][0] == x && board[0][1] == x && board[0][2] == x)
		return true;
	else if (board[1][0] == x && board[1][1] == x && board[1][2] == x)
		return true;
	else if (board[2][0] == x && board[2][1] == x && board[2][2] == x)
		return true;
	else if (board[0][0] == o && board[0][1] == o && board[0][2] == o)
		return true;
	else if (board[1][0] == o && board[1][1] == o && board[1][2] == o)
		return true;
	else if (board[2][0] == o && board[2][1] == o && board[2][2] == o)
		return true;
	else if (board[0][0] == x && board[1][0] == x && board[2][0] == x)
		return true;
	else if (board[0][1] == x && board[1][1] == x && board[2][1] == x)
		return true;
	else if (board[0][2] == x && board[1][2] == x && board[2][2] == x)
		return true;
	else if (board[0][0] == o && board[1][0] == o && board[2][0] == o)
		return true;
	else if (board[0][1] == o && board[1][1] == o && board[0][1] == o)
		return true;
	else if (board[0][2] == o && board[1][2] == o && board[2][2] == o)
		return true;
	else if (board[0][0] == x && board[1][1] == x && board[2][2] == x)
		return true;
	else if (board[0][0] == o && board[1][1] == o && board[2][2] == o)
		return true;
	else if (board[0][2] == x && board[1][1] == x && board[2][0] == x)
		return true;
	else if (board[0][2] == o && board[1][1] == o && board[2][0] == o)
		return true;
	else
		return false;
}


void TicTacToe::display()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
			if (j != 2)
				cout << "|";
		}
		cout << endl;
		if (i != 2)
			cout << "__|__|__\n";
		else
		{
			cout << "  |  |  \n";
		}


	}

}

int main()
{
	while (true)
	{
		TicTacToe game;
		int row, column;
		bool gamestate = false;
		bool success = true;
		int count = 0;
		cout << "Tic Tac Toe!" << endl;
		cout << "Enter Inputs as: row# col#, for example: 2 3" << endl;

		while (!gamestate && count != 9) {
			game.player = !game.player;
			do {
				if (!success || count != 0)
					system("cls");
				if (!success)
				{
					cout << "Invalid Entry! Try Again!\n\n";
				}
				game.display();
				cout << "\nEnter row and column for player ";
				if (game.player)
					cout << 'X';
				else
				{
					cout << 'O';
				}
				cout << ": ";

				cin >> row >> column;
				success = game.move(row, column);

			} while (!success);
			gamestate = game.endgame(); count++;
		}
		system("cls");
		game.display();
		if (gamestate)
		{
			if (game.player)
				cout << "Player X Wins!!!\n\n";
			else
			{
				cout << "Player O Wins!!!\n\n";
			}

		}

		else
		{
			cout << "Game Ended with a Draw!\n\n";
		}
	}
	return 0;
}