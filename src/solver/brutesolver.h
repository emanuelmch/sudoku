#pragma once

#include "solver.h"

#include <vector>

namespace Bill {
	namespace Sudoku {

		class BruteSolver : public Solver {
		public:
			BruteSolver() : callback(NULL) { }
			void solve(Board *);
			void registerCallback(SolverCallback);
		private:
			SolverCallback callback;
			std::vector<Board*> process(const Board *);
		};

	}
}
