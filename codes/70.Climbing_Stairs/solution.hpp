/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

class Solution {
   public:
    // overloading operator()
    int operator()(const int& n) { return climbStairs(n); }

    // function()
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        int num1 = 1, num2 = 1;
        for (int i = 2; i < n + 1; i++) {
            num2 += num1;
            num1 = num2 - num1;
        }
        return num2;
    }
};

#endif