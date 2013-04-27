#pragma once

#include "solver.h"

class BillSolverTest;

namespace Bill {
	namespace Sudoku {

		class BillSolver : public Solver {
		public:
			void solve(Board *);

		private:
			int possibilities[Board::GRID_SIZE][Board::GRID_SIZE][Board::GRID_SIZE + 1];

			void clearPossibilities();
			void fillPossibilities(Board*);
			void fillPossibilitiesEmpty(Board*, int x, int y);
			void fillPossibilitiesFilled(Board*, int x, int y);
			bool checkPossibilities(Board*);

			friend class ::BillSolverTest;
		};

	}
}
