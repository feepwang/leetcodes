/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::max;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return jump(nums); }

    // function()
    int jump(vector<int>& nums) {
        int rightmost = 0;

        int i = 0, sz = nums.size();
        int count = 0, tmp = 0;
        while (rightmost + 1 < sz  //   && i < sz
        ) {
            while (i <= rightmost) {
                tmp = max(tmp, i + nums[i]);
                i++;
            }
            rightmost = tmp;
            count++;
        }
        return count;
    }
};

#endif