/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
   public:
    // overloading operator()
    vector<vector<int>> operator()(vector<int>& nums) { return threeSum(nums); }

    // function()
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        auto sz = nums.size();
        if (sz < 3) return result;
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0) return result;

        for (int i = 0; i < sz - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = sz - 1;
            while (j < k) {
                //  这个循环的难点在于排除重复项
                auto sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    //  保证 j的下一个位置的值与当前值不同
                    //  如果放在 while循环里，j 的值可能会大于 k，从而跳出循环。
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                    k--;
                } else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }

        return result;
    }
};

#endif