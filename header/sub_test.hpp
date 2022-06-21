#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "sub.hpp"

TEST(SubTest, PositiveOperandsAndPositiveResult) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Sub* sub_test = new Sub(eight, four);

    EXPECT_EQ(sub_test->evaluate(), 4);
    EXPECT_EQ(sub_test->stringify(), "8.000000 - 4.000000");
}

TEST(SubTest, PositiveOperandsAndNegativeResult) {
    Op* eight = new Op(8);
    Op* four = new Op(4);
    Sub* sub_test = new Sub(four, eight);

    EXPECT_EQ(sub_test->evaluate(), -4);
    EXPECT_EQ(sub_test->stringify(), "4.000000 - 8.000000");
}

TEST(SubTest, NegativeOperandsAndPositiveResult) {
    Op* _eight = new Op(-8);
    Op* _four = new Op(-4);
    Sub* sub_test = new Sub(_four,_eight);

    EXPECT_EQ(sub_test->evaluate(), 4);
    EXPECT_EQ(sub_test->stringify(), "-4.000000 - -8.000000");
}

TEST(SubTest, NegativeOperandsAndNegativeResult) {
    Op* _eight = new Op(-8);
    Op* _four = new Op(-4);
    Sub* sub_test = new Sub(_eight, _four);

    EXPECT_EQ(sub_test->evaluate(), -4);
    EXPECT_EQ(sub_test->stringify(), "-8.000000 - -4.000000");
}

TEST(SubTest, PositiveDecimalResult) {
    Op* point_five = new Op(.5);
    Op* two = new Op(2);
    Sub* sub_test = new Sub(two, point_five);

    EXPECT_EQ(sub_test->evaluate(), 1.5);
    EXPECT_EQ(sub_test->stringify(), "2.000000 - 0.500000");
}

TEST(SubTest, NegativeDecimalResult) {
    Op* point_five = new Op(.5);
    Op* two = new Op(2);
    Sub* sub_test = new Sub(point_five, two);
    EXPECT_EQ(sub_test->evaluate(),-1.5);
    EXPECT_EQ(sub_test->stringify(), "0.500000 - 2.000000");
}

TEST(SubTest, SubtructFromZero) {
    Op* fifteen = new Op(15);
    Op* zero = new Op(0);
    Sub* sub_test = new Sub(zero, fifteen);

    EXPECT_EQ(sub_test->evaluate(), -15);
    EXPECT_EQ(sub_test->stringify(), "0.000000 - 15.000000");
}

TEST(SubTest, SubtructAZero) {
    Op* _fifteen = new Op(-15);
    Op* zero = new Op(0);
    Sub* sub_test = new Sub(_fifteen, zero);

    EXPECT_EQ(sub_test->evaluate(), -15);
    EXPECT_EQ(sub_test->stringify(), "-15.000000 - 0.000000");
}

TEST(SubTest, LargeValues) {
    Op* eight = new Op(8000000);
    Op* nine = new Op(9000000);
    Sub* sub_test = new Sub(eight, nine);

    EXPECT_EQ(sub_test->evaluate(), -1000000);
    EXPECT_EQ(sub_test->stringify(), "8000000.000000 - 9000000.000000");
}

TEST(SubTest, SmallValues) {
    Op* small_Pos_decimal = new Op(0.000003);
    Op* small_Neg_decimal = new Op(-0.000018);
    Sub* sub_test = new Sub(small_Neg_decimal,small_Pos_decimal);

    EXPECT_DOUBLE_EQ(sub_test->evaluate(), -0.000021);
    EXPECT_EQ(sub_test->stringify(),"-0.000018 - 0.000003");
}

TEST(SubTest, VerySmallValues) {
    Op* small_Pos_decimal = new Op(0.0000003);
    Op* small_Neg_decimal = new Op(-0.0000018);
    Sub* sub_test = new Sub(small_Neg_decimal,small_Pos_decimal);

    EXPECT_DOUBLE_EQ(sub_test->evaluate(), -0.0000021);
    EXPECT_NE(sub_test->stringify(),"-0.0000018 - 0.0000003");
    EXPECT_EQ(sub_test->stringify(),"-0.000002 - 0.000000");
}

#endif //__SUB_TEST_HPP__
