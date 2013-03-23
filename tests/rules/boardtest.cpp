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

inline static void testValidateBoard(const std::string values, const bool expected) {
	Board board;
	board.read(values);

	bool actual = board.validate();
	CPPUNIT_ASSERT_EQUAL(expected, actual);
}

void BoardTest::testValidateEmptyBoard() {
	testValidateBoard("000000000|000000000|000000000|000000000|000000000|000000000|000000000|000000000|000000000", true);
}

void BoardTest::testValidateHalfFullBoard() {
	testValidateBoard("942005010|000830040|035000000|680900420|700213006|093006075|000000730|020094000|060700954", true);
}

void BoardTest::testValidateFullBoard() {
	testValidateBoard("942675318|176832549|835149267|681957423|754213896|293486175|419568732|527394681|368721954", true);
}

void BoardTest::testValidateHalfFullInvalidBoard_Row() {
	testValidateBoard("942005010|000830040|035000000|680900420|700213006|093006075|300000730|020094000|060700954", false);
}

void BoardTest::testValidateFullInvalidBoard_Row() {
	// TODO: Try and find a better board for this test - as it is, it has both row, column AND mini duplicates
	testValidateBoard("942675318|176832549|835149267|681957423|754213896|293486175|319568732|527394681|368721954", false);
}

void BoardTest::testValidateHalfFullInvalidBoard_Column() {
	testValidateBoard("942005010|000830040|035000000|680900420|700213006|093006075|900000730|020094000|060700954", false);
}

void BoardTest::testValidateFullInvalidBoard_Column() {
	// TODO: Try and find a better board for this test - as it is, it has both row, column AND mini duplicates
	testValidateBoard("942675318|176832549|835149267|681957423|754213896|293486175|319568732|527394681|368721954", false);
}

void BoardTest::testValidateHalfFullInvalidBoard_Mini() {
	testValidateBoard("942005010|000830040|035000000|680900420|700213006|093006075|200000730|020094000|060700954", false);
}

void BoardTest::testValidateFullInvalidBoard_Mini() {
	// TODO: Try and find a better board for this test - as it is, it has both row, column AND mini duplicates
	testValidateBoard("942675318|176832549|835149267|681957423|754213896|293486175|319568732|527394681|368721954", false);
}

