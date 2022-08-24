//
// Created by feep on 2022/8/24.
//
//  Question:
// You are given two integer arrays of equal length target and arr. In one step,
// you can select any non-empty sub-array of arr and reverse it. You are allowed
// to make any number of steps.
//
// Return true if you can make arr equal to target or false otherwise.
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#ifndef LC_1460_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUB_ARRAYS_H
#define LC_1460_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUB_ARRAYS_H

#include <unordered_map>
#include <vector>

namespace lc {

class Solution {
  public:
    bool canBeEqual(std::vector<int> &target, std::vector<int> &arr) {
        if (target.size() != arr.size())
            return false;
        std::unordered_map<int, unsigned> mp{};
        for (auto i : target) {
            if (mp.find(i) != mp.end()) {
                mp[i]++;
            } else {
                mp.emplace(i, 1);
            }
        }

        for (auto i : arr) {
            if (mp.find(i) != mp.end()) {
                mp[i]--;
            } else {
                return false;
            }
        }

        for (const auto &pr : mp) {
            if (pr.second != 0) {
                return false;
            }
        }
        return true;
    }
};

} // namespace lc

#endif // LC_1460_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUB_ARRAYS_H
