#include "optimistic.h"

#include <cstddef>

Bill::Sudoku::OptimisticSolver::OptimisticSolver() {
	this->callback = NULL;
}

Bill::Sudoku::OptimisticSolver::~OptimisticSolver() {
}

bool Bill::Sudoku::OptimisticSolver::solve(Board *board) {
	return board;
}

void Bill::Sudoku::OptimisticSolver::registerCallback(SolverCallback call) {
	this->callback = call;
}
