#pragma once
#include <iostream>
using namespace std;

class Board
{
public:
	Board() 
	{
		populate();
		ships = 12;
	}
	~Board() { }
	void populate();
	char guess(int row, int col);
	bool place_ship(int row, int column, int direction, int len);
	char getCoord(int row, int col) const
	{
		return board[row][col];
	}
	void ship(int row, int col)
	{
		board[row][col] = 'B';
	}
	void hit(int row, int col)
	{
		board[row][col] = 'X';
		ships--;
	}
	int getShips()
	{
		return ships;
	}
	void miss(int row, int col)
	{
		board[row][col] = 'M';
	}
private:
	char board[10][10];
	int ships;
};
