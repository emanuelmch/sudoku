#pragma once

#include "solver.h"

#include <vector>

namespace Bill {
namespace Sudoku {

	struct SearchNode {
		Bill::Sudoku::Board *board;
	};

	class BruteSolver : public Solver {
	public:
		void solve(Board *);
		void registerCallback(SolverCallback);
	private:
		SolverCallback callback;
		SearchNode *createFirstNode(Board *);
		std::vector<SearchNode*> process(SearchNode *);
	};

}
}
