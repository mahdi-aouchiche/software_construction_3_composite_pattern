#ifndef __DIV_UNIT_TEST_HPP__
#define __DIV_UNIT_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"
#include "op.hpp"

TEST(DivTest, NegativeNumbers) {
    Op* _one = new Op(-1);
    Op* _five = new Op(-5);
    Div* divTest = new Div(_one, _five);
    
    EXPECT_EQ(divTest->evaluate(), 0.2);
    EXPECT_EQ(divTest->stringify(), "(-1.000000) / (-5.000000)");
}

TEST(DivTest, NegativeAndPositive) {
    Op* _one = new Op(-1);
    Op* five = new Op(5);
    Div* divTest = new Div(_one, five);

    EXPECT_EQ(divTest->evaluate(), -0.2);
    EXPECT_EQ(divTest->stringify(), "(-1.000000) / (5.000000)");
}

TEST(DivTest, DivideZeroByNonZeroNumber) {
    Op* _nine = new Op(-9);
    Op* zero = new Op(0);
    Div* divTest = new Div(zero, _nine);

    EXPECT_EQ(divTest->evaluate(), 0);
    EXPECT_EQ(divTest->stringify(), "(0.000000) / (-9.000000)");
}

TEST(DivTest, DivPositiveNum) {
    Op* nine = new Op(9);
    Op* eight = new Op(8);
    Div* divTest = new Div(nine, eight);

    EXPECT_EQ(divTest->evaluate(), 1.125);
    EXPECT_EQ(divTest->stringify(), "(9.000000) / (8.000000)");
}

TEST(DivTest, DivideByZero) {
    Op* eight = new Op(8);
    Op* zero = new Op(0);
    Div* divTest = new Div(eight, zero);

    EXPECT_THROW(divTest->evaluate(), runtime_error);
    EXPECT_EQ(divTest->stringify(), "(8.000000) / (0.000000)");
}

TEST(DivTest, Decimals) {
    Op* point_five = new Op(.5);
    Op* two_point_eight = new Op(2.8);
    Div* divTest = new Div(two_point_eight, point_five);

    EXPECT_EQ(divTest->evaluate(), 5.6);
    EXPECT_EQ(divTest->stringify(), "(2.800000) / (0.500000)");
}

#endif //__DIV_UNIT_TEST_HPP__

