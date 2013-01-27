#include "boardtest.h"

#include <iostream>

using Bill::Sudoku::Board;

CPPUNIT_TEST_SUITE_REGISTRATION(BoardTest);

void BoardTest::setUp() {}
void BoardTest::tearDown() {}

void BoardTest::testClear() {
	Board board;
	board.clear();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::stringstream err;
			err << i << ":" << j;

			int v = board.get(i, j);
			CPPUNIT_ASSERT_EQUAL_MESSAGE(err.str(), 0, v);
		}
	}
}

