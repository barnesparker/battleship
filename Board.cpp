#include "Board.h"

void Board::populate()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 'O';
		}
	}
}

char Board::guess(int row, int col)
{
	if (board[row][col] == 'B')
	{
		return 'X';
	}
	else
	{
		return 'M';
	}
}

bool Board::place_ship(int row, int column, int direction, int len)
{
	int temp_row = row;
	int temp_col = column;
	for (int i = 0; i < len; i++)
	{
		if (temp_row > 10 || temp_row < 0 || temp_col > 10 || temp_col < 0 || board[temp_row][temp_col] == 'B')
		{
			return false;
		}
		switch (direction)
		{
		case 1:
			temp_col--;
			break;
		case 2:
			temp_col++;
			break;
		case 3:
			temp_row--;
			break;
		case 4:
			temp_row++;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		board[row][column] = 'B';
		switch (direction)
		{
		case 1:
			column--;
			break;
		case 2:
			column++;
			break;
		case 3:
			row--;
			break;
		case 4:
			row++;
			break;
		}
	}
	return true;
}
