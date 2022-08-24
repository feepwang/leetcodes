//
// Created by feep on 2022/8/24.
//

#include <gtest/gtest.h>

#include "1460.Make_Two_Arrays_Equal_by_Reversing_Sub-arrays.h"

TEST(lc, 1460) {
    lc::Solution sol{};

    std::vector<int> t1{1, 2, 3, 4}, a1{2, 4, 1, 3};
    ASSERT_TRUE(sol.canBeEqual(t1, a1) == true);

    std::vector<int> t2{7}, a2{7};
    ASSERT_TRUE(sol.canBeEqual(t2, a2) == true);

    std::vector<int> t3{3, 7, 9}, a3{3, 7, 11};
    ASSERT_TRUE(sol.canBeEqual(t3, a3) == false);

    std::vector<int> t4{1, 2, 2, 3}, a4{1, 1, 2, 3};
    ASSERT_TRUE(sol.canBeEqual(t4, a4) == false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}