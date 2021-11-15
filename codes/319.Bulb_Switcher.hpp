/*
 * Qustion:
 * There are n bulbs that are initially off. You first turn on all the bulbs,
 * then you turn off every second bulb.
 *
 * On the third round, you toggle every third bulb (turning on if it's off or
 * turning off if it's on). For the ith round, you toggle every i bulb. For the
 * nth round, you only toggle the last bulb.
 *
 * Return the number of bulbs that are on after n rounds.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/bulb-switcher
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>
#include <numeric>

namespace lc {

class Solution {
   public:
    int operator()(const int& n) { return bulbSwitch(n); }

   private:
    int bulbSwitch(int n) {
        return std::sqrt(n + 0.5);

        //std::vector<bool> cnt(n + 1, false);

        //for (int i = 1; i <= n; ++i) {
        //    for (int cur = i; cur <= n; cur += i) {
        //        cnt[cur] = !cnt[cur];
        //    }
        //}

        //int result = 0;
        //for (auto b : cnt) {
        //    if (b) ++result;
        //}

        //return result;
    }
};

}  // namespace lc

#endif