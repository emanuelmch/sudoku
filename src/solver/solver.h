#pragma once

#include "../rules/board.h"

class SolverTest;

namespace Bill {
namespace Sudoku {

	typedef void (*SolverCallback)(const Board *, const int column, const int row, const int value);

	class Solver {
	public:
		Solver();
		~Solver();

		void solve(Board *);
		void registerCallback(SolverCallback);

	private:
		SolverCallback callback;

		int possibilities[Board::GRID_SIZE][Board::GRID_SIZE][Board::GRID_SIZE + 1];

		void clearPossibilities();
		void fillPossibilities(Board*);
		void fillPossibilities(Board*, int x, int y);
		bool checkPossibilities(Board*);

		void moveFound(Bill::Sudoku::Board *board, const int line, const int row, const int value);

		friend class ::SolverTest;
	};

}
}
