#pragma once

#include "../../src/rules/board.h"

#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BoardTest);

	CPPUNIT_TEST(testClear);

	CPPUNIT_TEST(testCopyEquals);
	CPPUNIT_TEST(testCopyDifferent);
	CPPUNIT_TEST(testCopyEmptyToFull);
	CPPUNIT_TEST(testCopyFullToEmpty);

	CPPUNIT_TEST(testValidateEmptyBoard);
	CPPUNIT_TEST(testValidateHalfFullBoard);
	CPPUNIT_TEST(testValidateFullBoard);
	CPPUNIT_TEST(testValidateHalfFullInvalidBoard_Row);
	CPPUNIT_TEST(testValidateFullInvalidBoard_Row);
	CPPUNIT_TEST(testValidateHalfFullInvalidBoard_Column);
	CPPUNIT_TEST(testValidateFullInvalidBoard_Column);
	CPPUNIT_TEST(testValidateHalfFullInvalidBoard_Mini);
	CPPUNIT_TEST(testValidateFullInvalidBoard_Mini);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testClear();

	void testCopyEquals();
	void testCopyDifferent();
	void testCopyEmptyToFull();
	void testCopyFullToEmpty();

	void testValidateEmptyBoard();
	void testValidateHalfFullBoard();
	void testValidateFullBoard();
	void testValidateHalfFullInvalidBoard_Row();
	void testValidateFullInvalidBoard_Row();
	void testValidateHalfFullInvalidBoard_Column();
	void testValidateFullInvalidBoard_Column();
	void testValidateHalfFullInvalidBoard_Mini();
	void testValidateFullInvalidBoard_Mini();
};

