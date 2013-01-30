
#include "rules/board.h"

#include "solvers/solver.h"
#include "solvers/optimistic.h"

#include <iostream>

using Bill::Sudoku::Board;
using Bill::Sudoku::Solver;

static const int BOARD_COUNT = 3;

static inline void chooseBoard(Board *board, const int index) {
	std::string boards[BOARD_COUNT];
	boards[0] = "001457936|007000200|306009005|130900042|864010309|070005018|700000503|009070001|613598400";	
	boards[1] = "001457936|000000200|306000005|130900040|804010309|070005018|700000503|009000000|613598400";	
	boards[2] = "942005010|000830040|035000000|680900420|700213006|093006075|000000730|020094000|060700954";

	board->readString(boards[index]);
}

static inline void printBoard(const Board *board) {
	std::cout << board->usedCells() << "/" << Board::CELL_AMOUNT << "  ";

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const int v = board->get(j, i);
			std::cout << v;
		}
		std::cout << "|";
	}
	std::cout << std::endl;
}

static inline Solver *chooseSolver() {
	return new Bill::Sudoku::OptimisticSolver();
}

//static void callback(const Board *board, const int column, const int row, const int value) {
	//Board *b = (Board*)board;
	//b = b;
	//std::cout << "New value: " << column << ":" << row << ":" << value << std::endl;
//}

int main() {
	Board board;
	Solver *solver;

	solver = chooseSolver();
	//solver->registerCallback(callback);

	for (int i = 0; i < BOARD_COUNT; i++)
	{
		chooseBoard(&board, i);

		std::cout << "Board chosen: ";
		printBoard(&board);

		bool result = solver->solve(&board);
		if (result)
			std::cout << "=)            ";
		else
			std::cout << "=(            ";

		printBoard(&board);
	}

	delete solver;

	return 0;
}

