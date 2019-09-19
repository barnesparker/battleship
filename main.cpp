#include <iostream>
#include "Board.h"
using namespace std;


const void display(Board myBoard)
{
	cout << endl << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << i << "  ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < 10; j++)
		{
			cout << myBoard.getCoord(i, j) << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool random_turn(Board& guess_board, Board& opp_board)
{
	int row = 0;
	int col = 0;
	bool valid = false;
	while (!valid)
	{
		row = rand() % 10;
		col = rand() % 10;
		if (!(guess_board.getCoord(row, col) == 'X' || guess_board.getCoord(row, col) == 'M'))
		{
			valid = true;
		}
	}
	cout << "The computer takes a shot at (" << row << "," << col << ")" << endl;
	if (opp_board.getCoord(row, col) == 'B')
	{
		guess_board.hit(row, col);
		cout << "Hit!" << endl;
		if (guess_board.getShips() == 0)
		{
			return false;
		}
	}
	else
	{
		guess_board.miss(row, col);
		cout << "Miss!" << endl;
	}
	return true;
}
bool guess(Board& guess_board, Board& opp_board)
{
	bool valid = true;
	int row = 0;
	int col = 0;
	while (valid)
	{
		display(guess_board);
		cout << "Enter a row and column of where you want to shoot: " << endl;
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> col;
		if (guess_board.getCoord(row, col) == 'X' || guess_board.getCoord(row, col) == 'M')
		{
			cout << "You've already attacked there!" << endl;
		}
		else
		{
			valid = false;
		}
	}
	if (opp_board.getCoord(row, col) == 'B')
	{
		guess_board.hit(row, col);
		cout << "Hit!" << endl;
		if (guess_board.getShips() == 0)
		{
			return false;
		}
	}
	else
	{
		guess_board.miss(row, col);
		cout << "Miss!" << endl;
	}
	return true;
}
void battle(Board board1, Board board2, int players)
{
	Board opp1;
	Board opp2;
	int winner = 2;
	bool game = true;
	cout << "It's time to battle!" << endl << endl;
	while (game)
	{
		cout << "Player 1's Turn" << endl << endl;
		game = guess(opp1, board2);
		if (game)
		{
			if (players == 2)
			{
				cout << "Player 2's Turn" << endl << endl;
				game = guess(opp2, board1);
			}
			else
			{
				game = random_turn(opp2, board1);
			}
		}
		else if (!game)
		{
			winner = 1;
		}
	}
	cout << "Player " << winner << "Wins!!";
}
void random_setup(Board& myBoard)
{
	for (int i = 3; i < 6; i++)
	{
		int start_col = rand() % 11;
		int start_row = rand() % 11;
		int rand_dir = (rand() % 4) + 1;
		if (!myBoard.place_ship(start_col, start_row, rand_dir, i))
		{
			i--;
		}
	}
}
void setup(Board& myBoard)
{
	int direction = 0;
	int row = 0;
	int column = 0;
	for (int i = 3; i < 6; i++)
	{
		display(myBoard);
		cout << "Choose where to place your ship of size " << i << " by entering a: " << endl;
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		cout << "Which direction would you like to have your ship go?" << endl;
		cout << "1 - Left" << endl << "2 - Right" << endl << "3 - Up" << endl << "4 - Down" << endl;
		cin >> direction;
		cout << endl << endl;
		if (!myBoard.place_ship(row, column, direction, i))
		{
			cout << "You can't place a ship there, try again!" << endl;
			i--;
		}
		else
		{
			myBoard.place_ship(row, column, direction, i);
		}
	}
}
void single_player()
{
	Board myBoard;
	Board CGI_board;
	cout << "Single Player" << endl << endl;
	random_setup(CGI_board);
	display(CGI_board);
	setup(myBoard);
	battle(myBoard, CGI_board, 1);
}
void multiplayer()
{
	Board board1;
	Board board2;
	cout << "Multiplayer" << endl << endl;
	cout << "***Player 1***" << endl << endl;
	setup(board1);
	cout << "***Player 2***" << endl << endl;
	setup(board2);
	battle(board1, board2, 2);
}
int main()
{
	int more = 1;
	int menu_option = 0;
	while (menu_option != 3 && more != 0)
	{
		cout << "Menu" << endl << endl;
		cout << "1 - Single Player" << endl;
		cout << "2 - Multiplayer" << endl;
		cout << "3 - Quit" << endl;
		cin >> menu_option;
		if (menu_option == 1)
		{
			single_player();
		}
		else if (menu_option == 2)
		{
			multiplayer();
		}
		else if (menu_option == 3)
		{
			more = 0;
		}
		else
		{
			cout << "Please enter 1,2 or 3" << endl;
		}
		cout << "Would you like to play again?" << endl;
		cout << "1 - Yes";
		cout << "0 - No";
		cin >> more;
	}
	system("pause");
	return 0;
}