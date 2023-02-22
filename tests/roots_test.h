#ifndef ROOTS_TEST_H
#define ROOTS_TEST_H

#include <gtest/gtest.h>
#include <math.h>

extern "C" {
#include "func.h"
}

const double abs_error = 0.000001;

TEST(rootsTest, two_solves) {
    roots res = quadr_equation(4, 1, 0);
    ASSERT_DOUBLE_EQ(-0.25, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(-4, 0, 1);
    ASSERT_DOUBLE_EQ(-0.5, res.first);
    ASSERT_DOUBLE_EQ(0.5, res.second);

    res = quadr_equation(0.5, -2.5, 3);
    ASSERT_DOUBLE_EQ(2, res.first);
    ASSERT_DOUBLE_EQ(3, res.second);

    res = quadr_equation(-2.72, -2.72, 2.72);
    ASSERT_NEAR(-1.6180339888, res.first, abs_error);
    ASSERT_NEAR(0.6180339888, res.second, abs_error);
}

TEST(rootsTest, one_solve) {
    roots res = quadr_equation(-1.23, 0, 0);
    ASSERT_DOUBLE_EQ(0, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(2, -20, 50);
    ASSERT_DOUBLE_EQ(5, res.first);
    ASSERT_DOUBLE_EQ(5, res.second);

    res = quadr_equation(-1, -2.46, -1.5129);
    ASSERT_DOUBLE_EQ(-1.23, res.first);
    ASSERT_DOUBLE_EQ(-1.23, res.second);
}

TEST(rootsTest, no_solves) {
    roots res = quadr_equation(-0.1, 0.5, -0.7);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(4, 0, 1);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));
}

TEST(rootsTest, non_quadr_equation) {
    roots res = quadr_equation(0, 0, 0);
    ASSERT_TRUE(isinf(res.first));
    ASSERT_TRUE(isinf(res.second));

    res = quadr_equation(0, 0, 100);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(0, 100, 0);
    ASSERT_DOUBLE_EQ(0, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(0, 3, 1);
    ASSERT_NEAR(-0.3333333333, res.first, abs_error);
    ASSERT_NEAR(-0.3333333333, res.second, abs_error);
}

#endif // ROOTS_TEST_H
