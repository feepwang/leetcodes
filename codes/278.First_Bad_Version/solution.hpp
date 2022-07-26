/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

bool isBadVersion(int version);

class Solution {
   public:
    // overloading operator()
    int operator()(const int& n) { return firstBadVersion(n); }

    // function()
    int firstBadVersion(int n) {
        int low = 1, high = n, pivot;

        // 二分查找
        while (low < high) {
            // 防止溢出
            pivot = low + (high - low) / 2;
            if (isBadVersion(pivot))
                high = pivot;
            else
                low = pivot + 1;
            if (isBadVersion(low)) break;
        }
        return low;
    }
};

#endif