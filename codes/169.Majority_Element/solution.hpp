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
    // int operator()(int i,int j);

    // function()
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 0;
        for (const auto& i : nums) {
            if (i == candidate) {
                ++count;
            } else if (--count < 0) {
                candidate = i;
                count = 1;
            }
        }
        return candidate;
    }
};

#endif