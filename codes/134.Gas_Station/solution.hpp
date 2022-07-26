/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cstddef>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& gas, vector<int>& cost) {
        return canCompleteCircuit(gas, cost);
    }

    // function()
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result;
        int sum = 0, all = 0;
        for (size_t i = 0, sz = gas.size(); i < sz; i++) {
            auto tmp = gas[i] - cost[i];
            sum += tmp, all += tmp;
            if (sum < 0) {
                sum = 0;
                result = i + 1;
            }
        }

        return all < 0 ? -1 : result;
    }
};

#endif