#include "billsolver.h"

using Bill::Sudoku::Board;

void Bill::Sudoku::BillSolver::solve(Board *board) {
	clearPossibilities();
	do {
		fillPossibilities(board);
	} while(checkPossibilities(board));
}

void Bill::Sudoku::BillSolver::clearPossibilities() {
	const int arraySize = sizeof(possibilities) / sizeof(possibilities[0][0][0]);
	std::fill(&possibilities[0][0][0], &possibilities[0][0][0] + arraySize, 0);
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
					board->set(i, j, only);
					foundAny = true;
				}
			}
		}
	}
	return foundAny;
}

