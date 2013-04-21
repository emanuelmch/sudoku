#include "billsolvertest.h"

#include <iostream>

using Bill::Sudoku::BillSolver;
using Bill::Sudoku::Board;

CPPUNIT_TEST_SUITE_REGISTRATION(BillSolverTest);

void BillSolverTest::setUp() {}
void BillSolverTest::tearDown() {}

void BillSolverTest::testClearPossibilities() {
	BillSolver solver;

	for (int i = 0; i < Board::GRID_SIZE; i++) {
		for (int j = 0; j < Board::GRID_SIZE; j++) {
			for (int x = 0; x < Board::GRID_SIZE + 1; x++) {
				solver.possibilities[i][j][x] = 2;
			}
		}
	}

	solver.clearPossibilities();

	for (int i = 0; i < Board::GRID_SIZE; i++) {
		for (int j = 0; j < Board::GRID_SIZE; j++) {
			for (int x = 1; x < Board::GRID_SIZE + 1; x++) {
				int v = solver.possibilities[i][j][x];

				std::stringstream err;
				err << "Array[" << i << "][" << j << "][" << x << "] is " << v;

				CPPUNIT_ASSERT_EQUAL_MESSAGE(err.str(), 0, v);
			}
		}
	}


}
