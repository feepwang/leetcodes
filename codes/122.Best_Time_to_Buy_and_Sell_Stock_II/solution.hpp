/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& prices) { return maxProfit(prices); }

    // function()
    int maxProfit(vector<int>& prices) {
        int profit{0};
        for (int i = 1, sz = prices.size(); i < sz; i++)
            profit += std::max(0, prices[i] - prices[i - 1]);
        return profit;
    }
};

#endif