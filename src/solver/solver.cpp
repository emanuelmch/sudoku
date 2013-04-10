#include "solver.h"

#include <cstddef>
#include <cstring>

using Bill::Sudoku::Board;

Bill::Sudoku::Solver::Solver() {
	this->callback = NULL;
}

Bill::Sudoku::Solver::~Solver() {
}

void Bill::Sudoku::Solver::solve(Board *board) {
	do {
		clearPossibilities();
		fillPossibilities(board);
	} while (checkPossibilities(board));
}

void Bill::Sudoku::Solver::clearPossibilities() {
	memset(possibilities, 0, sizeof(int) * Board::GRID_SIZE * Board::GRID_SIZE * (Board::GRID_SIZE + 1));
}

void Bill::Sudoku::Solver::fillPossibilities(Board *board) {
	for (int x = 0; x < Board::GRID_SIZE; x++) {
		for (int y = 0; y < Board::GRID_SIZE; y++) {
			if (board->get(x, y) == 0)
				fillPossibilities(board, x, y);
		}
	}
}

void Bill::Sudoku::Solver::fillPossibilities(Board *board, int x, int y) {
	for (int i = 0; i < Board::GRID_SIZE; i++) {
		// Look for "used up" possibilities in the same column/row
		int c = board->get(x, i);
		int r = board->get(i, y);

		possibilities[x][y][c]++;
		possibilities[x][y][r]++;
	}

	// Look for "used up" possibilities in the same mini-grid
	{
		const int lookup_table[] = {0,0,0,3,3,3,6,6,6};
		int min_c = lookup_table[x];
		int max_c = min_c + 3;
		int min_r = lookup_table[y];
		int max_r = min_r + 3;

		for (int c = min_c; c < max_c; c++) {
			for (int r = min_r; r < max_r; r++) {
				int value = board->get(c, r);
				possibilities[x][y][value]++;
			}
		}
	}
}

bool Bill::Sudoku::Solver::checkPossibilities(Board *board) {
	bool foundAny = false;
	for (int i = 0; i < Board::GRID_SIZE; i++) {
		for (int j = 0; j < Board::GRID_SIZE; j++) {
			int only = 0;
			for (int x = 1; x < Board::GRID_SIZE + 1; x++) {
				if (possibilities[i][j][x] == 0) {
					if (only == 0)
						only = x;
					else
						only = -1;
				}
			}
			if (only > 0)
			{
				moveFound(board, i, j, only);
				foundAny = true;
			}
		}
	}
	return foundAny;
}

void Bill::Sudoku::Solver::registerCallback(SolverCallback call) {
	this->callback = call;
}

void Bill::Sudoku::Solver::moveFound(Board *board, const int column, const int row, const int value) {
	board->set(column, row, value);
	if (this->callback)
		callback(board, column, row, value);
}

