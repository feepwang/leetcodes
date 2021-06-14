/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

int guess(int num);

class Solution {
   public:
    // overloading operator()
    int operator()(const int& n) { return guessNumber(n); }

    // function()
    int guessNumber(int n) {
        int low = 0, high = n;
        int pivot = n / 2;
        while (low < high) {
            auto tmp = guess(pivot);
            if (tmp) {
                if (tmp == 1)
                    low = pivot + 1;
                else
                    high = pivot;
                pivot = low + (high - low) / 2;
            } else
                return pivot;
        }
        return low;
    }
};

#endif