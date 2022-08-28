/*
 * Question:
 * Given an integer n, return the nth digit of the infinite integer sequence [1,
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/nth-digit
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>

namespace lc {

class Solution {
   public:
    int operator()(int n) { return findNthDigit(n); }

   private:
    int findNthDigit(int n) {
        int digit = 1;
        //  防止溢出
        //  count 代表当前位数所使用的数的位数和, start 代表当前位的第一个数
        unsigned count = 9, start = 1;
        while (count < n) {
            // n-count 是剩余的位数
            n -= count;
            ++digit;
            start *= 10;
            count = digit * 9 * start;
        }
        //
        start += (n - 1) / digit;
        return std::to_string(start)[(n - 1) % digit] - '0';
    }
};

}  // namespace lc

#endif
