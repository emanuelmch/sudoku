#include "board.h"

Bill::Sudoku::Board::Board() {
	clear();
}

Bill::Sudoku::Board::~Board() {
}

const int Bill::Sudoku::Board::get(const int x, const int y) const {
	return values[x][y];
}

void Bill::Sudoku::Board::set(const int x, const int y, const int value) {
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

bool Bill::Sudoku::Board::isFilled() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (values[i][j] == 0)
				return false;
		}
	}

	return true;
}

