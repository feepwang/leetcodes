/*
 * Question:
 * Given a positive integer n, you can apply one of the following operations:
 *
 * If n is even, replace n with n / 2.
 * If n is odd, replace n with either n + 1 or n - 1.
 * Return the minimum number of operations needed for n to become 1.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/integer-replacement
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>
#include <cmath>

namespace lc {

class Solution {
   public:
    int operator()(const int& n) { return integerReplacement(n); }

   private:
    int integerReplacement(int n) {
        int result{};

        while (n != 1) {
            if (n % 2 == 0) {
                ++result;
                n /= 2;
            } else if (n % 4 == 1) {
                result += 2;
                n /= 2;
            } else {
                if (n == 3) {
                    result += 2;
                    n = 1;
                } else {
                    result += 2;
                    n = n / 2 + 1;
                }
            }
        }

        return result;
    }
};

}  // namespace lc

#endif