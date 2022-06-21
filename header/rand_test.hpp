#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, Positive_Values) {
    srand(time(0));
    Rand* test = new Rand();
    
    EXPECT_GE(test->evaluate(), 0 );
    EXPECT_LT(test->evaluate(), 100 );

    EXPECT_EQ(test->stringify(), to_string(test->evaluate()));
}

TEST(RandTest, Negative_Values) {
    srand(time(0));
    Rand* test = new Rand();

    EXPECT_FALSE(test->evaluate() < 0);
    EXPECT_EQ(test->stringify(), to_string(test->evaluate()));
}

#endif //__RAND_TEST_HPP__
