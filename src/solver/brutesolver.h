#pragma once

#include "solver.h"

#include <vector>

namespace Bill {
	namespace Sudoku {

		class BruteSolver : public Solver {
		public:
			BruteSolver() { }
			void solve(Board *);
		private:
			std::vector<Board*> *process(const Board *) const;
		};

	}
}
