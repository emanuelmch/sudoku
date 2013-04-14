#pragma once

#include "solver.h"

namespace Bill {
namespace Sudoku {

	class BruteSolver : public Solver {
	public:
		void solve(Board *);
		void registerCallback(SolverCallback);
	private:
		SolverCallback callback;
	};

}
}

