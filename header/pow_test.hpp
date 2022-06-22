#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "pow.hpp"

TEST(PowTest, PositiveValues) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Pow* pow_test = new Pow(eight, four);

    EXPECT_EQ(pow_test->evaluate(), 4096);
    EXPECT_EQ(pow_test->stringify(), "(8.000000) ** (4.000000)");
}

TEST(PowTest, DecimalBase) {
    Op* point_five = new Op(.5);
    Op* two = new Op(2);
    Pow* pow_test = new Pow(point_five, two);

    EXPECT_DOUBLE_EQ(pow_test->evaluate(),.25);
    EXPECT_EQ(pow_test->stringify(), "(0.500000) ** (2.000000)");
}

TEST(PowTest, PositiveBaseAndZeroExponent) {
    Op* fifteen = new Op(15);
    Op* zero = new Op(0);
    Pow* pow_test = new Pow(fifteen, zero);

    EXPECT_EQ(pow_test->evaluate(), 1);
    EXPECT_EQ(pow_test->stringify(), "(15.000000) ** (0.000000)");
}

TEST(PowTest, NegativeBaseAndZeroExponent) {
    Op* _fifteen = new Op(-15);
    Op* zero = new Op(0);
    Pow* pow_test = new Pow(_fifteen, zero);

    EXPECT_EQ(pow_test->evaluate(), 1);
    EXPECT_EQ(pow_test->stringify(), "(-15.000000) ** (0.000000)");
}

TEST(PowTest, ZeroBaseAndPositiveExponent) {
    Op* fifteen = new Op(15);
    Op* zero = new Op(0);
    Pow* pow_test = new Pow(zero, fifteen);

    EXPECT_EQ(pow_test->evaluate(), 0);
    EXPECT_EQ(pow_test->stringify(), "(0.000000) ** (15.000000)");
}

TEST(PowTest, ZeroBaseAndNegativeExponent) {
    Op* _fifteen = new Op(-15);
    Op* zero = new Op(0);
    Pow* pow_test = new Pow(zero, _fifteen);

    EXPECT_THROW(pow_test->evaluate(), runtime_error);
    EXPECT_EQ(pow_test->stringify(), "(0.000000) ** (-15.000000)");
}

TEST(PowTest, ZeroBaseAndZeroExponent) {
    Op* zero = new Op(0);
    Pow* pow_test = new Pow(zero, zero);

    EXPECT_EQ(pow_test->evaluate(), 1);
    EXPECT_EQ(pow_test->stringify(), "(0.000000) ** (0.000000)");
}

TEST(PowTest, PowEvaluateLarge) {
    Op* eight = new Op(8);
    Op* nine = new Op(9);
    Pow* pow_test = new Pow(eight, nine);

    EXPECT_EQ(pow_test->evaluate(), 134217728);
    EXPECT_EQ(pow_test->stringify(), "(8.000000) ** (9.000000)");
}

TEST(PowTest, NegativeExponent) {
    Op* point_five = new Op(.5);
    Op* _two = new Op(-2);
    Pow* pow_test = new Pow(point_five, _two);
    EXPECT_EQ(pow_test->evaluate(),4);
    EXPECT_EQ(pow_test->stringify(), "(0.500000) ** (-2.000000)");
}

#endif //__POW_TEST_HPP__