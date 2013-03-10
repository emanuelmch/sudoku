#include "solver.h"

#include <cstddef>

using Bill::Sudoku::Board;

Bill::Sudoku::Solver::Solver() {
	this->callback = NULL;
}

Bill::Sudoku::Solver::~Solver() {
}

static int lookForMove(const Board *board, const int column, const int row) {
	int possibilities[10] = {0,};

	// Look for "used up" possibilites on the same column and/or row
	for (int i = 0; i < 9; i++) {
		int c = board->get(column, i);
		int r = board->get(i, row);

		possibilities[c] = 1;
		possibilities[r] = 1;
	}

	// Look for "used up" possiblites on the same mini-grid
	{
		const int lookup_table[] = {0,0,0,3,3,3,6,6,6};
		int min_c = lookup_table[column];
		int max_c = min_c + 3;
		int min_r = lookup_table[row];
		int max_r = min_r + 3;

		for (int c = min_c; c < max_c; c++)
			for (int r = min_r; r < max_r; r++)
			{
				int value = board->get(c, r);
				possibilities[value] = 1;
			}
	}

	// See if there's only one possibility :)
	int only = 0;
	for (int i = 1; i < 10; i++) {
		if (possibilities[i] == 0) {
			if (only == 0)
				only = i;
			else
				return 0;
		}
	}

	return only;
}

bool Bill::Sudoku::Solver::solve(Board *board) {
	bool found;
	do {
		found = false;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board->get(i,j) == 0) {
					int move = lookForMove(board, i, j);
					if (move) {
						board->set(i, j, move);
						moveFound(board, j, i, move);
						found = true;
					}
				}
			}
		}
	} while (found);

	return board->isFilled();
}

void Bill::Sudoku::Solver::registerCallback(SolverCallback call) {
	this->callback = call;
}

void Bill::Sudoku::Solver::moveFound(const Board *board, const int column, const int row, const int value) {
	if (this->callback)
		callback(board, column, row, value);
}

