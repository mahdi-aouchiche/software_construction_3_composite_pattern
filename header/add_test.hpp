#ifndef __ADD_UNIT_TEST_HPP__
#define __ADD_UNIT_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/op.hpp"
#include "../header/add.hpp"

using namespace std; 

TEST(AddTest, zerroAddition) {
    Op* zero = new Op(0);
    Add* additionTest = new Add(zero, zero);

    EXPECT_EQ(additionTest->evaluate(), 0);
    EXPECT_EQ(additionTest->stringify(), "0.000000 + 0.000000");
}

TEST(AddTest, NegativeNumbers) {
    Op* _one = new Op(-1);
    Op* _five = new Op(-5);
    Add* additionTest = new Add(_one, _five);

    EXPECT_EQ(additionTest->evaluate(), -6);
    EXPECT_EQ(additionTest->stringify(), "-1.000000 + -5.000000");
}

TEST(AddTest, NegativeAndPositive) {
    Op* _one = new Op(-1);
    Op* five = new Op(5);
    Add* additionTest = new Add(_one, five);

    EXPECT_EQ(additionTest->evaluate(), 4);
    EXPECT_EQ(additionTest->stringify(), "-1.000000 + 5.000000");
}

TEST(AddTest, AddUpToZero) {
    Op* _nine = new Op(-9);
    Op* nine = new Op(9);
    Add* additionTest = new Add(_nine, nine);

    EXPECT_EQ(additionTest->evaluate(), 0);
    EXPECT_EQ(additionTest->stringify(), "-9.000000 + 9.000000");
}

TEST(AddTest, Decimals) {
    Op* point_nine = new Op(.9);
    Op* point_one = new Op(.1);
    Add* additionTest = new Add(point_nine, point_one);

    EXPECT_EQ(additionTest->evaluate(), 1);
    EXPECT_EQ(additionTest->stringify(), "0.900000 + 0.100000");
}

TEST(AddTest, DecimalAndPositive) {
    Op* point_five = new Op(.5);
    Op* two = new Op(2);
    Add* additionTest = new Add(point_five,two);

    EXPECT_EQ(additionTest->evaluate(), 2.5);
    EXPECT_EQ(additionTest->stringify(), "0.500000 + 2.000000");
}

TEST(AddTest, DecimalAndNegative) {
    Op* _nine = new Op(-9);
    Op* point_nine = new Op(.9);
    Add* additionTest = new Add(_nine,point_nine);

    EXPECT_EQ(additionTest->evaluate(), -8.1);
    EXPECT_EQ(additionTest->stringify(), "-9.000000 + 0.900000");
}

TEST(AddTest, PositiveNumbers) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Add* additionTest = new Add(eight, four);

    EXPECT_EQ(additionTest->evaluate(), 12);
    EXPECT_EQ(additionTest->stringify(), "8.000000 + 4.000000");
}

TEST(AddTest, NegativNumbers) {
    Op* _fifteen = new Op(-15);
    Op* _ten = new Op(-10);
    Add* additionTest = new Add(_fifteen, _ten);

    EXPECT_EQ(additionTest->evaluate(), -25);
    EXPECT_EQ(additionTest->stringify(),"-15.000000 + -10.000000");
}

#endif //__ADD_UNIT_TEST_HPP__
