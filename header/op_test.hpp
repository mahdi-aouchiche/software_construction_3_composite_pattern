#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OP_Positive_Values) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, Op_Negative_Values) {
    Op* test = new Op(-1);
    EXPECT_EQ(test->evaluate(), -1);
    EXPECT_EQ(test->stringify(), "-1.000000");
}

TEST(OpTest, Op_Double_Values) {
    Op* test = new Op(9.28);
    EXPECT_EQ(test->evaluate(), 9.28);
    EXPECT_EQ(test->stringify(), "9.280000");
}

TEST(OpTest, Op_Zero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "0.000000");
}

#endif //__OP_TEST_HPP__
