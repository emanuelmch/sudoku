#include "board.h"

Bill::Sudoku::Board::Board()
{
	clear();
}

Bill::Sudoku::Board::~Board()
{
}

int Bill::Sudoku::Board::get(int x, int y)
{
	return values[x][y];
}

void Bill::Sudoku::Board::clear() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			values[i][j] = 0;
		}
	}
}

