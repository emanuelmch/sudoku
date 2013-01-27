#include "board.h"

Bill::Sudoku::Board::Board() {
	clear();
}

Bill::Sudoku::Board::~Board() {
}

int Bill::Sudoku::Board::get(int x, int y) {
	return values[x][y];
}

int Bill::Sudoku::Board::set(int x, int y, int value)
{
	values[x][y] = value;
}

void Bill::Sudoku::Board::readString(const std::string value)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c = value[i * 10 + j];
			values[j][i] = c - '0';
		}
	}
}

void Bill::Sudoku::Board::clear() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			values[i][j] = 0;
		}
	}
}

