/**
 * @file 658.Find_K_Clostest_Elements.h
 * @author feep (me@feep.wang)
 * @brief
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022
 *
 * Question:
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 *
 * 整数 a 比整数 b 更接近 x 需要满足：
 *
 *     |a - x| < |b - x| 或者
 *     |a - x| == |b - x| 且 a < b
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/find-k-closest-elements
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_658_FIND_K_CLOSTEST_ELEMENTS_H
#define LC_658_FIND_K_CLOSTEST_ELEMENTS_H

#include <algorithm>
#include <vector>

namespace lc {

class Solution {
  public:
    std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
        int right = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};

} // namespace lc

#endif

