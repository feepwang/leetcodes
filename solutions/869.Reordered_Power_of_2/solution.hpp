/*
 * Question
 * You are given an integer n. We reorder the digits in any order (including the
 * original order) such that the leading digit is not zero.
 *
 * Return true if and only if we can do this so that the resulting number is a
 * power of two.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/reordered-power-of-2
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
#include <unordered_set>

class Solution {
   public:
    // overloading operator()
    bool operator()(const int& n) { return reorderedPowerOf2(n); }

    // function
    std::string countDigits(int n) {
        std::string cnt(10, 0);
        while (n) {
            cnt[n % 10]++;
            n /= 10;
        }
        return cnt;
    }

    // function()
    bool reorderedPowerOf2(int n) {
        std::unordered_set<std::string> uSet;
        for (int n = 1; n <= 1e9; n <<= 1) {
            uSet.insert(countDigits(n));
        }

        return uSet.count(countDigits(n));
    }
};

#endif