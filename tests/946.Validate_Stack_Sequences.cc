/**
 * @file 946.Validate_Stack_Sequences.cc
 * @author feep (me@feep.wang)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "gtest/gtest.h"

#include "946.Validate_Stack_Sequences/solution.hpp"

TEST(lc, 946) {
    Solution sol{};
    std::vector<int> pushed{ 1,2,3,4,5 }, popped{ 4,5,3,2,1 };
    ASSERT_TRUE(sol.validateStackSequences(pushed, popped));

    popped = { 4,3,5,1,2 };
    ASSERT_FALSE(sol.validateStackSequences(pushed, popped));
}


