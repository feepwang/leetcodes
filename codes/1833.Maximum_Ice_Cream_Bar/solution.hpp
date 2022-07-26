/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& costs, const int& coins) {
        return maxIceCream(costs, coins);
    }

    // function()
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int i = 0, sz = costs.size(); i < sz; i++) {
            auto cst = costs[i];
            if (cst > coins)
                break;
            else {
                coins -= cst;
                count++;
            }
        }
        return count;
    }
};

#endif