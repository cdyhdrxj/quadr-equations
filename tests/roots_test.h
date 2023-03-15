#ifndef ROOTS_TEST_H
#define ROOTS_TEST_H

#include <gtest/gtest.h>
#include <math.h>

extern "C" {
#include "func.h"
}

const double abs_error = 0.000001;

TEST(rootsTest, two_solutions) {
    roots res = quadr_equation(4, 1, 0);
    ASSERT_EQ(2, res.num);
    ASSERT_DOUBLE_EQ(-0.25, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(-4, 0, 1);
    ASSERT_EQ(2, res.num);
    ASSERT_DOUBLE_EQ(-0.5, res.first);
    ASSERT_DOUBLE_EQ(0.5, res.second);

    res = quadr_equation(0.5, -2.5, 3);
    ASSERT_EQ(2, res.num);
    ASSERT_DOUBLE_EQ(2, res.first);
    ASSERT_DOUBLE_EQ(3, res.second);

    res = quadr_equation(-2.72, -2.72, 2.72);
    ASSERT_EQ(2, res.num);
    ASSERT_NEAR(-1.6180339888, res.first, abs_error);
    ASSERT_NEAR(0.6180339888, res.second, abs_error);
}

TEST(rootsTest, one_solution) {
    roots res = quadr_equation(-1.23, 0, 0);
    ASSERT_EQ(1, res.num);
    ASSERT_DOUBLE_EQ(0, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(2, -20, 50);
    ASSERT_EQ(1, res.num);
    ASSERT_DOUBLE_EQ(5, res.first);
    ASSERT_DOUBLE_EQ(5, res.second);

    res = quadr_equation(-1, -2.46, -1.5129);
    ASSERT_EQ(1, res.num);
    ASSERT_DOUBLE_EQ(-1.23, res.first);
    ASSERT_DOUBLE_EQ(-1.23, res.second);
}

TEST(rootsTest, no_solutions) {
    roots res = quadr_equation(-0.1, 0.5, -0.7);
    ASSERT_EQ(0, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(4, 0, 1);
    ASSERT_EQ(0, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));
}

TEST(rootsTest, non_quadr_equation) {
    roots res = quadr_equation(0, 0, 0);
    ASSERT_TRUE(res.num > 2);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(0, 0, 100);
    ASSERT_EQ(0, res.num);

    res = quadr_equation(0, 100, 0);
    ASSERT_EQ(1, res.num);
    ASSERT_DOUBLE_EQ(0, res.first);
    ASSERT_DOUBLE_EQ(0, res.second);

    res = quadr_equation(0, 3, 1);
    ASSERT_EQ(1, res.num);
    ASSERT_NEAR(-0.3333333333, res.first, abs_error);
    ASSERT_NEAR(-0.3333333333, res.second, abs_error);
}

TEST(rootsTest, overflow){
    roots res = quadr_equation(1, 1e200, -1);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(10e200, 1, 1e200);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(0.45e308, 1, -1);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(0.44e308, 1e154, -1);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(1e-310, 1, -1);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));

    res = quadr_equation(1e-310, -1, -1);
    ASSERT_EQ(-1, res.num);
    ASSERT_TRUE(isnan(res.first));
    ASSERT_TRUE(isnan(res.second));
}

#endif // ROOTS_TEST_H
