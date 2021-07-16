/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::max;
using std::min;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return maxProduct(nums); }

    // function()
    int maxProduct(vector<int>& nums) {
        int ma = nums[0], mi = ma;
        int result = ma;
        for (int i = 1, sz = nums.size(); i < sz; i++) {
            int tmp = nums[i];
            ma = max({tmp, ma * tmp, mi * tmp});
            mi = min({tmp, ma * tmp, mi * tmp});
            result = max(result, ma);
        }
        return result;
    }
};

#endif