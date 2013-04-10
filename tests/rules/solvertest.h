#pragma once

#include "../../src/solver/solver.h"

#include <cppunit/extensions/HelperMacros.h>

class SolverTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(SolverTest);

	CPPUNIT_TEST(testClearPossibilities);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testClearPossibilities();
};
