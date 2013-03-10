
#include "rules/board.h"
#include "solver/solver.h"

#include <iostream>

using Bill::Sudoku::Board;
using Bill::Sudoku::Solver;

static const int BOARD_COUNT = 5;

static inline void readBoard(Board *board, const int index) {
	std::string boards[BOARD_COUNT];
	boards[0] = "001457936|007000200|306009005|130900042|864010309|070005018|700000503|009070001|613598400";	
	boards[1] = "942005010|000830040|035000000|680900420|700213006|093006075|000000730|020094000|060700954";
	boards[2] = "000190400|000700600|206548090|000904300|008000000|001370000|000800045|010009200|000013987";
	boards[3] = "000080410|600300900|800000035|080504000|005100000|730009150|410002003|000000601|200000080";
	boards[4] = "070285010|008903500|000000000|500010008|010000090|900040003|000000000|002408600|090632080";

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

int main() {
	Board board;
	Solver solver;

	for (int i = 0; i < BOARD_COUNT; i++)
	{
		readBoard(&board, i);

		bool result = solver.solve(&board);
		if (result)
		{
			std::cout << "Board " << i << " solved! =)" << std::endl;
		}
		else
		{
			std::cout << "Board " << i << " not solved! =( " << std::endl;

			std::cout << "Before: ";
			Board original;
			readBoard(&original, i);
			printBoard(&original);

			std::cout << "After: ";
			printBoard(&board);
		}
	}

	return 0;
}

