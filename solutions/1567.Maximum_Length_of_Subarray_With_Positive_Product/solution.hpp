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
    // int operator()(int i,int j);

    // function()
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int posi = 0, nega = 0;
        for (const int& i : nums) {
            if (i > 0) {
                posi++;
                nega = nega > 0 ? nega + 1 : 0;
            } else if (i < 0) {
                int tmp = nega;
                nega = posi + 1;
                posi = tmp > 0 ? tmp + 1 : 0;
            } else
                posi = 0, nega = 0;
            ans = max(ans, posi);
        }
        return ans;
    }
};

#endif