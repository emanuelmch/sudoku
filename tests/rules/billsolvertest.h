#pragma once

#include "../../src/solver/billsolver.h"

#include <cppunit/extensions/HelperMacros.h>

class BillSolverTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(BillSolverTest);

	CPPUNIT_TEST(testClearPossibilities);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testClearPossibilities();
};
