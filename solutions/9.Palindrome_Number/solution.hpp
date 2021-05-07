/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    bool isPalindrome(int x) {
        if (x < 0) return false;
        unsigned long tmp = 0, flag = x;
        while (x != 0) {
            tmp = tmp * 10 + x % 10;
            x = x / 10;
        }
        return flag == tmp;
    }
};

#endif