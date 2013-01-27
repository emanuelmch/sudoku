#pragma once

#include "../../src/rules/board.h"

#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BoardTest);

	CPPUNIT_TEST(testClear);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testClear();
};

