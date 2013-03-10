#pragma once

#include "../rules/board.h"

namespace Bill {
namespace Sudoku {

	typedef void (*SolverCallback)(const Board *, const int column, const int row, const int value);

	class Solver {
	public:
		Solver();
		~Solver();

		bool solve(Board *);
		void registerCallback(SolverCallback);

	private:
		SolverCallback callback;
		void moveFound(const Bill::Sudoku::Board *board, const int line, const int row, const int value);
	};

}
}
