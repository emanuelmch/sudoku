#pragma once

#include "solver.h"

namespace Bill {
namespace Sudoku {

	class OptimisticSolver : public Solver {
	public:
		OptimisticSolver();
		~OptimisticSolver();

		bool solve(Board *);
		void registerCallback(SolverCallback);
	private:
		SolverCallback callback;
		void moveFound(const Bill::Sudoku::Board *board, const int line, const int row, const int value);
	};

}
}
