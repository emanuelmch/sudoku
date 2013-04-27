#include "billsolver.h"

#include <cstddef>
#include <cstring>
#include <iostream>

using Bill::Sudoku::Board;

Bill::Sudoku::BillSolver::BillSolver() : callback(NULL) {
}

Bill::Sudoku::BillSolver::~BillSolver() {
}

void Bill::Sudoku::BillSolver::solve(Board *board) {
	clearPossibilities();
	do {
		fillPossibilities(board);
	} while(checkPossibilities(board));
}

void Bill::Sudoku::BillSolver::clearPossibilities() {
	memset(possibilities, 0, sizeof(int) * Board::GRID_SIZE * Board::GRID_SIZE *(Board::GRID_SIZE + 1));
}

void Bill::Sudoku::BillSolver::fillPossibilities(Board *board) {
	for(int x = 0; x < Board::GRID_SIZE; x++) {
		for(int y = 0; y < Board::GRID_SIZE; y++) {
			if(board->get(x, y) == 0)
				fillPossibilities(board, x, y);
		}
	}
}

void Bill::Sudoku::BillSolver::fillPossibilities(Board *board, int x, int y) {
	for(int i = 0; i < Board::GRID_SIZE; i++) {
		// Look for "used up" possibilities in the same column/row
		int c = board->get(x, i);
		int r = board->get(i, y);

		possibilities[x][y][c] = 1;
		possibilities[x][y][r] = 1;
	}

	// Look for "used up" possibilities in the same mini-grid
	{
		const int lookup_table[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
		int min_c = lookup_table[x];
		int max_c = min_c + 3;
		int min_r = lookup_table[y];
		int max_r = min_r + 3;

		for(int c = min_c; c < max_c; c++) {
			for(int r = min_r; r < max_r; r++) {
				int value = board->get(c, r);
				possibilities[x][y][value] = 1;
			}
		}
	}
}

bool Bill::Sudoku::BillSolver::checkPossibilities(Board *board) {
	bool foundAny = false;
	for(int i = 0; i < Board::GRID_SIZE; i++) {
		for(int j = 0; j < Board::GRID_SIZE; j++) {
			if(board->get(i, j) == 0) {
				int only = 0;
				for(int x = 1; x < Board::GRID_SIZE + 1; x++) {
					if(possibilities[i][j][x] == 0) {
						if(only == 0)
							only = x;
						else
							only = -1;
					}
				}
				if(only > 0) {
					moveFound(board, i, j, only);
					foundAny = true;
				}
			}
		}
	}
	return foundAny;
}

void Bill::Sudoku::BillSolver::registerCallback(SolverCallback call) {
	this->callback = call;
}

void Bill::Sudoku::BillSolver::moveFound(Board *board, const int column, const int row, const int value) {
	board->set(column, row, value);
	if(this->callback)
		callback(board, column, row, value);
}

