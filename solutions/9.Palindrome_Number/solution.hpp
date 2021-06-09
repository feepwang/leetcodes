/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

class Solution {
   public:
    // overloading operator()
<<<<<<< HEAD
    bool operator()(const int& x) { return isPalindrome(x); }
=======
    // int operator()(int i,int j);
>>>>>>> e2946796342d86ae54ccf2f7406f94d85930c322

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