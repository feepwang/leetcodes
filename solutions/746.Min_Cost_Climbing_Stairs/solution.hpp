/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::min;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int> cost) { return minCostClimbingStairs(cost); }

    // function()
    int minCostClimbingStairs(vector<int>& cost) {
        int val1 = 0, val2 = 0;
        int i = 2, sz = cost.size();
        int tmp = 0;
        while (i++ < sz) {
            tmp = val2;
            val2 = min(val1 + cost[i - 2], val2 + cost[i - 1]);
            val1 = tmp;
        }
        return val2;
    }
};

#endif