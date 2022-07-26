/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& prices) { return maxProfit(prices); }

    // function()
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int profit = 0;
        for (const auto& i : prices) {
            profit = max(profit, i - mn);
            mn = min(mn, i);
        }

        return profit;
    }
};

#endif