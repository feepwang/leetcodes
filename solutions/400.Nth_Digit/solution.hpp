/*
 * Question
 * Given an integer n, return the nth digit of the infinite integer sequence [1,
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/nth-digit
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cmath>
#include <string>

class Solution {
   public:
    // overloading operator()
    int operator()(const int& n) { return findNthDigit(n); }

    // function()
    // int findNthDigit(int n) {
    //     if (n == 0) return 0;

    //     int digit = 1;
    //     long start = 1;
    //     long index_count = digit * 9 * start;

    //     while (index_count < n) {
    //         n -= index_count;
    //         ++digit;
    //         start *= 10;
    //         index_count = digit * 9 * start;
    //     }

    //     long num = start + (n - 1) / digit;
    //     int remainder = (n - 1) % digit;

    //     auto snum = std::to_string(num);
    //     return snum[remainder] - '0';
    // }

    int findNthDigit(int n) {
        int digit = 1, start = 1, count = 9;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = digit * 9 * start;
        }

        int num = start + (n - 1) / digit;
        int remainder = (n - 1) % digit;

        auto snum = std::to_string(num);
        return snum[remainder] - '0';
    }
};

#endif