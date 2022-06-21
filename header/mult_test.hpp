#ifndef __MULT_UNIT_TEST_HPP__
#define __MULT_UNIT_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"
using namespace std;

TEST(MultTest, ZerosMultiplication) {
    Op* zero = new Op(0);
    Mult* multTest = new Mult(zero, zero);

    EXPECT_EQ(multTest->evaluate(), 0);
    EXPECT_EQ(multTest->stringify(), "(0.000000) * (0.000000)");
}

TEST(MultTest, MultiplyByZero) {
    Op* _nine = new Op(-9);
    Op* zero = new Op(0);

    Mult* multTest = new Mult(_nine, zero);
    EXPECT_EQ(multTest->evaluate(), 0);
    EXPECT_EQ(multTest->stringify(), "(-9.000000) * (0.000000)");

    Mult* multTest1 = new Mult(zero, _nine);
    EXPECT_EQ(multTest1->evaluate(), 0);
    EXPECT_EQ(multTest1->stringify(), "(0.000000) * (-9.000000)");
}

TEST(MultTest, NegativeNumbers) {
    Op* _one = new Op(-1);
    Op* _five = new Op(-5);
    Mult* multTest = new Mult(_one, _five);

    EXPECT_EQ(multTest->evaluate(), 5);
    EXPECT_EQ(multTest->stringify(), "(-1.000000) * (-5.000000)");
}

TEST(MultTest, NegativeAndPositive) {
    Op* _one = new Op(-1);
    Op* five = new Op(5);
    Mult* multTest = new Mult(_one, five);
    EXPECT_EQ(multTest->evaluate(), -5);
    EXPECT_EQ(multTest->stringify(), "(-1.000000) * (5.000000)");
}

TEST(MultTest, PositiveNumbers) {
    Op* nine = new Op(9);
    Op* eight = new Op(8);
    Mult* multTest = new Mult(nine, eight);
    EXPECT_EQ(multTest->evaluate(), 72);
    EXPECT_EQ(multTest->stringify(), "(9.000000) * (8.000000)");
}

TEST(MultTest, DecimalMultiplication) {
    Op* point_five = new Op(.5);
    Op* two_point_eight = new Op(2.8);
    Mult* multTest = new Mult(point_five,two_point_eight);

    EXPECT_EQ(multTest->evaluate(), 1.4);
    EXPECT_EQ(multTest->stringify(), "(0.500000) * (2.800000)");
}

TEST(MultTest, SmallNumbers) {
    Op* small_Pos_Num = new Op(0.0008);
    Op* small_Neg_Num = new Op(-.0004);
    Mult* multTest = new Mult(small_Pos_Num, small_Neg_Num);

    EXPECT_EQ(multTest->evaluate(), -.00000032);
    EXPECT_EQ(multTest->stringify(), "(0.000800) * (-0.000400)");
}

TEST(MultTest, LargeNumbers) {
    Op* Large_Pos_Num = new Op(5e+9);
    Op* Large_Neg_Num = new Op(-8e+9);
    Mult* multTest = new Mult(Large_Pos_Num, Large_Neg_Num);

    EXPECT_EQ(multTest->evaluate(), -4e+19);
    EXPECT_EQ(multTest->stringify(), "(5000000000.000000) * (-8000000000.000000)");
}

#endif //__ADD_UNIT_TEST_HPP__
