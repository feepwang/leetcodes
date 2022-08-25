//
// Created by feep on 2022/8/21.
//

#include <gtest/gtest.h>

#include "1455.Check_If_a_Word_Occurs_As_a_Prefix_of_Any_Word_in_a_Sentence.hpp"

TEST(lc, 1455) {
    lc::Solution sol{};

    ASSERT_EQ(sol.isPrefixOfWord("i love eating burger", "burg"), 4);
    ASSERT_EQ(sol.isPrefixOfWord("this problem is an easy problem", "pro"), 2);
    ASSERT_EQ(sol.isPrefixOfWord("i am tired", "you"), -1);
    ASSERT_EQ(sol.isPrefixOfWord("b bu bur burg burger", "burg"), 4);
}
