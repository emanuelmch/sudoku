#pragma once

#include "solver.h"

class BillSolverTest;

namespace Bill {
namespace Sudoku {

	class BillSolver : public Solver {
	public:
		BillSolver();
		~BillSolver();

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

		friend class ::BillSolverTest;
	};

}
}
