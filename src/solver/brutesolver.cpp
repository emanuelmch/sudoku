#include "brutesolver.h"

#include <queue>
#include <vector>

using Bill::Sudoku::Board;

using std::queue;
using std::vector;

void Bill::Sudoku::BruteSolver::solve(Board *originalBoard) {
	Board *firstBoard = new Board();
	firstBoard->copy(originalBoard);

	queue<Board*> boards;
	boards.push(firstBoard);

	do {
		// Process the first board in the queue
		Board *board = boards.front();
		vector<Board*> newBoards = process(board);

		// Remove already process board from the queue
		boards.pop();

		// Go through the new boards
		for(vector<Board*>::iterator it = newBoards.begin(); it != newBoards.end(); it++) {
			Board *board = (*it);

			if(board->isFilled()) {
				// Only valid boards get to this point, so if it's filled, we found our solution!
				originalBoard->copy(board);
				// I know, this will leave many objects un-deleted. I'll take care of it later
				return;
			} else {
				// If it ain't filled yet, just put it in the queue for further processing
				boards.push((*it));
			}
		}

		// Now that we are done with it, delete the board
		delete board;
		// If we get to a point where we have no more boards to process, then that's when we give up
	} while(!boards.empty());
}

void Bill::Sudoku::BruteSolver::registerCallback(SolverCallback call) {
	this->callback = call;
}

vector<Board*> createPossibleBoards(const Board *original, int x, int y) {
	vector<Board*> boards;

	for(int i = 1; i <= 9; i++) {
		Board *board = new Board();
		board->copy(original);
		board->set(x, y, i);

		if(board->validate()) {
			boards.push_back(board);
		} else {
			delete board;
		}
	}

	return boards;
}

vector<Board*> Bill::Sudoku::BruteSolver::process(const Board *board) {
	for(int y = 0; y < 9; y++) {
		for(int x = 0; x < 9; x++) {
			if(board->get(x, y) == 0)
				return createPossibleBoards(board, x, y);
		}
	}

	return vector<Board*>();
}
