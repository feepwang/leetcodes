/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

class Solution {
   public:
    // overloading operator()
    int operator()(const int& i) { return reverse(i); }

    // function()
    int reverse(int x) {
        int y = 0;
        while (x != 0) {
            if (y > 214748364 || y < -214748364) return 0;

            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y;
    }
};

#endif