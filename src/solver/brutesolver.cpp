#include "brutesolver.h"

#include <queue>
#include <vector>

using Bill::Sudoku::Board;

using std::queue;
using std::vector;

void Bill::Sudoku::BruteSolver::solve(Board *originalBoard) {
	bool foundSolution = false;
	Board *firstBoard = new Board();
	firstBoard->copy(originalBoard);

	queue<Board*> boards;
	boards.push(firstBoard);

	do {
		// Process the first board in the queue
		Board *board = boards.front();

		if (foundSolution) {
			// If we already have a solution, let's just delete whatever's left to process
			delete board;
			continue;
		}

		vector<Board*> *newBoards = process(board);

		// Remove already process board from the queue
		boards.pop();

		// Go through the new boards
		for(vector<Board*>::iterator it = newBoards->begin(); it != newBoards->end(); it++) {
			Board *newBoard = (*it);

			if (foundSolution) {
				// If we already have a solution, let's just delete whatever's left to process
				delete newBoard;
			} else if (newBoard->isFilled()) {
				// Only valid boards get to this point, so if it's filled, we found our solution!
				originalBoard->copy(newBoard);
				foundSolution = true;
				delete newBoard;
			} else {
				// If it ain't filled yet, just put it in the queue for further processing
				boards.push((*it));
			}
		}

		delete newBoards;
		delete board;
	} while(!boards.empty());
}

void Bill::Sudoku::BruteSolver::registerCallback(SolverCallback call) {
	this->callback = call;
}

vector<Board*> *createPossibleBoards(const Board *original, const int x, const int y) {
	vector<Board*> *boards = new vector<Board*>();

	for(int i = 1; i <= Board::GRID_SIZE; i++) {
		Board *board = new Board();
		board->copy(original);
		board->set(x, y, i);

		if(board->validate()) {
			boards->push_back(board);
		} else {
			delete board;
		}
	}

	return boards;
}

vector<Board*> *Bill::Sudoku::BruteSolver::process(const Board *board) const {
	for(int y = 0; y < Board::GRID_SIZE; y++) {
		for(int x = 0; x < Board::GRID_SIZE; x++) {
			if(board->get(x, y) == 0)
				return createPossibleBoards(board, x, y);
		}
	}

	return new vector<Board*>();
}
