/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    vector<vector<int>> operator()(vector<int>& nums, const int& target) {
        return fourSum(nums, target);
    }

    // function()
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        auto sz = nums.size();
        if (sz < 4) return result;
        sort(nums.begin(), nums.end());
        if (4 * nums.front() > target || 4 * nums.back() < target)
            return result;

        for (int i = 0; i < sz - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < sz - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1, l = sz - 1;
                while (k < l) {
                    auto sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        k++, l--;
                    } else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        return result;
    }
};

#endif