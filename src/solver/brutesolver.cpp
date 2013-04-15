#include "brutesolver.h"

#include <queue>
#include <vector>

using Bill::Sudoku::SearchNode;
using Bill::Sudoku::Board;

using std::queue;
using std::vector;

void Bill::Sudoku::BruteSolver::solve(Board *originalBoard) {
	SearchNode *firstNode = this->createFirstNode(originalBoard);

	queue<SearchNode*> nodes;
	nodes.push(firstNode);

	do {
		// Process the first node in the queue
		SearchNode *node = nodes.front();
		vector<SearchNode*> newNodes = process(node);

		// Remove already process node from the queue
		nodes.pop();

		// Go through the new nodes
		for(vector<SearchNode*>::iterator it = newNodes.begin(); it != newNodes.end(); it++) {
		    Board *board = (*it)->board;
		    // If one of them is valid, GREAT! We found our solution
		    if (board->validate()) {
			originalBoard->copy(board);
			// I know, this will many object un-deleted. I'll take care of it later
			return;
		    }
		    // Otherwise, put it in the queue for further processing
		    nodes.push((*it));
		}

		// Now that we are done with it, delete the module
		delete node;
	} while (!nodes.empty());

}

void Bill::Sudoku::BruteSolver::registerCallback(SolverCallback call) {
	this->callback = call;
}

SearchNode *Bill::Sudoku::BruteSolver::createFirstNode(Board *board) {
	SearchNode *node = new SearchNode();
	node->board = board;
	return node;
}

vector<SearchNode*> Bill::Sudoku::BruteSolver::process(SearchNode *node) {
	vector<SearchNode*> newVector;
	return newVector;
}
