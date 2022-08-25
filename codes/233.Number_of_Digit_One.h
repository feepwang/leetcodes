/*
 * Question:
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/number-of-digit-one
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>

namespace lc {

class Solution {
   public:
    int operator()(const int& n) { return countDigitOne(n); }

   private:
    int countDigitOne(int n) {
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + std::min(std::max(n % (mulk*10)-mulk+1,0ll),mulk);
            mulk *= 10;
        }
        return ans;
    }
};

}  // namespace lc

#endif