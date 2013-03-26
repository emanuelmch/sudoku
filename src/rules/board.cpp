#include "board.h"

typedef int BoardValues[9][9];

Bill::Sudoku::Board::Board() {
	clear();
}

Bill::Sudoku::Board::~Board() {
}

int Bill::Sudoku::Board::get(const int x, const int y) const {
	return values[x][y];
}

void Bill::Sudoku::Board::set(const int x, const int y, const int value) {
	values[x][y] = value;
}

int Bill::Sudoku::Board::usedCells() const {
	int count = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (values[j][i])
				count++;
		}
	}

	return count;
}

void Bill::Sudoku::Board::read(const std::string value) {
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

static inline bool validateMiniGrid(BoardValues &values, int x, int y) {
	bool usedValues[10] = {false,};

	for (int i = x; i < (x + 3); i++) {
		for (int j = y; j < (y + 3); j++) {
			int v = values[i][j];

			if (v == 0)
				continue;

			if (usedValues[v])
				return false;

			usedValues[v] = true;
		}
	}

	return true;
}

bool Bill::Sudoku::Board::validate() {
	// First, validate rows and columns
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (values[i][j] == 0)
				continue;

			for (int x = 0; x < 9; x++) {
				if (i != x && values[i][j] == values[x][j])
					return false;
				if (j != x && values[i][j] == values[i][x])
					return false;
			}
		}	
	}

	// Now, validate every mini-grid
	for (int i = 0; i < GRID_SIZE; i += MINI_GRID_SIZE) {
		for (int j = 0; j < GRID_SIZE; j += MINI_GRID_SIZE) {
			bool result = validateMiniGrid(values, i, j);
			if (!result)
				return false;
		}
	}

	return true;
}
