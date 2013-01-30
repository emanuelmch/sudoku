
#include "rules/board.h"

#include "solvers/solver.h"
#include "solvers/optimistic.h"

#include <iostream>

using Bill::Sudoku::Board;
using Bill::Sudoku::Solver;

static inline void chooseBoard(Board *board) {
	const int BOARD_COUNT = 2;
	std::string boards[BOARD_COUNT];
	boards[0] = "001457936|000000200|306000005|130900040|804010309|070005018|700000503|009000000|613598400";	
	boards[1] = "942005010|000830040|035000000|680900420|700213006|093006075|000000730|020094000|060700954";

	for (int i = 0; i < BOARD_COUNT; i++) {
		std::cout << "Board " << i + 1 << ":" << boards[i] << std::endl;
	}

	std::cout << "Choose your board[1-" << BOARD_COUNT << "]: ";

	int choice;
	std::cin >> choice;

	board->readString(boards[choice - 1]);
}

static inline void printBoard(const Board *board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const int v = board->get(j, i);
			std::cout << v;
		}
		std::cout << std::endl;
	}
}

static inline Solver *chooseSolver() {
	return new Bill::Sudoku::OptimisticSolver();
}

static void callback(const Board *board, const int column, const int row, const int value) {
	Board *b = (Board*)board;
	b = b;
	std::cout << "New value: " << column << ":" << row << ":" << value << std::endl;
}

int main() {
	Board board;
	Solver *solver;

	chooseBoard(&board);

	std::cout << "Board chosen:" << std::endl;
	printBoard(&board);

	solver = chooseSolver();

	solver->registerCallback(callback);

	bool result = solver->solve(&board);

	std::cout << std::endl << std::endl;
	if (result)
		std::cout << "Horray!" << std::endl << std::endl;
	else
		std::cout << "=(" << std::endl << std::endl;

	printBoard(&board);

	delete solver;
	return 0;
}

