/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

class Solution {
   public:
    // overloading operator()
    int operator()(const int& num) { return findComplement(num); }

    // function()
    int findComplement(int num) {
        int result{0};
        int bit{0}, digit{0};
        while (num) {
            bit = num & 1 ? 0 : 1;
            result |= bit << digit;
            num >>= 1;
            ++digit;
        }
        return result;
    }
};

#endif