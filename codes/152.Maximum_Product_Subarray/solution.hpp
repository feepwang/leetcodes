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
        int ma{nums[0]}, mi{nums[0]}, res{nums[0]};

        for (int i = 1; i < nums.size(); ++i) {
            int tmp = ma, n = nums[i];
            ma = max({n, n * ma, n * mi});
            mi = min({n, n * tmp, n * mi});
            res = max(res, ma);
        }

        return res;
    }
};

#endif