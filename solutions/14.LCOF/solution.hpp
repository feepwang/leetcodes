/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cmath>

class Solution {
   public:
    // overloading operator()
    int operator()(const int& n) { return cuttingRope(n); }

    // function()
    int cuttingRope(int n) {
        return n <= 3 ? n - 1 : pow(3, n / 3) * 4 / (4 - n % 3);
    }
};

#endif