#pragma once

#include "../../src/rules/board.h"

#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BoardTest);

	CPPUNIT_TEST(testClear);
	
	CPPUNIT_TEST(testValidateEmptyBoard);
	CPPUNIT_TEST(testValidateHalfFullBoard);
	CPPUNIT_TEST(testValidateFullBoard);
	CPPUNIT_TEST(testValidateHalfFullInvalidBoard);
	CPPUNIT_TEST(testValidateFullInvalidBoard);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testClear();

	void testValidateEmptyBoard();
	void testValidateHalfFullBoard();
	void testValidateFullBoard();
	void testValidateHalfFullInvalidBoard();
	void testValidateFullInvalidBoard();
};

