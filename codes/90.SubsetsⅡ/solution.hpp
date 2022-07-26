/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    vector<vector<int>> operator()(vector<int>& nums) {
        return subsetsWithDup(nums);
    }

    // function()
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result{vector<int>{}};

        size_t first = 0, second = first, end = nums.size();
        do {
            ++second;
            if (second != end && nums[first] == nums[second]) {
                continue;
            } else {
                size_t count = second - first, sz = result.size();
                for (int i = 0; i < sz; ++i) {
                    vector<int> tmp{result[i]};
                    for (int j = 0; j < count; ++j) {
                        tmp.push_back(nums[first]);
                        result.push_back(tmp);
                    }
                }
                first = second;
            }
        } while (second != end);

        return result;
    }
};

#endif