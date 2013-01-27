#include "rules/board.h"

#include <iostream>

using Bill::Sudoku::Board;

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

static inline void printBoard(Board *board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << board->get(j, i);
		}
		std::cout << std::endl;
	}
}

int main() {
	Board board;

	chooseBoard(&board);

	std::cout << "Board chosen:" << std::endl;
	printBoard(&board);

	return 0;
}

