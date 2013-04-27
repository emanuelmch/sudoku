#pragma once

#include "../rules/board.h"

namespace Bill {
namespace Sudoku {

	typedef void (*SolverCallback)(const Board *, const int column, const int row, const int value);

	class Solver {
	public:
        virtual ~Solver() { }
		virtual void solve(Board *) = 0;
		virtual void registerCallback(SolverCallback) = 0;
	};

}
}
