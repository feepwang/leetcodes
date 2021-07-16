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
    int operator()(vector<int>& values) {
        return maxScoreSightseeingPair(values);
    }

    // function()
    int maxScoreSightseeingPair(vector<int>& values) {
        int pos = values[0] > values[1] ? 0 : 1;
        int result = values[0] + values[1] - 1;
        for (int i = 2, sz = values.size(), tmp{0}; i < sz; i++) {
            tmp = pos - i + values[pos] + values[i];
            if ((values[pos] - values[i]) < (i - pos)) pos = i;
            if (result < tmp) result = tmp;
        }
        return result;
    }
};

#endif