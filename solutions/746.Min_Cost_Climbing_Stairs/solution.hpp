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
        int first{}, second{};
        for (int sz = cost.size(), tmp{}, pos{2}; pos <= sz; ++pos) {
            tmp = second;
            second = min(first + cost[pos - 2], second + cost[pos - 1]);
            first = tmp;
        }
        return second;
    }
};

#endif