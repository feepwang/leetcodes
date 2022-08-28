/**
 * @file 658.Find_K_Clostest_Elements.cc
 * @author feep (me@feep.wang)
 * @brief
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022
 */

#include "658.Find_K_Clostest_Elements.h"

#include "gtest/gtest.h"

TEST(lc,658) {
    lc::Solution sol;

    std::vector<int> vec{1,2,3,4,5};
    ASSERT_TRUE((sol.findClosestElements(vec, 4, 3) == std::vector<int>{1,2,3,4}));

    ASSERT_TRUE((sol.findClosestElements(vec, 4,-1) == std::vector<int>{1,2,3,4}));
}

