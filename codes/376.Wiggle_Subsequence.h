/*
 * Question:
 * A wiggle sequence is a sequence where the differences between successive
 * numbers strictly alternate between positive and negative. The first
 * difference (if one exists) may be either positive or negative. A sequence
 * with one element and a sequence with two non-equal elements are trivially
 * wiggle sequences.
 *
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
 * (6, -3, 5, -7, 3) alternate between positive and negative. In contrast, [1,
 * 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not
 * because its first two differences are positive, and the second is not because
 * its last difference is zero. A subsequence is obtained by deleting some
 * elements (possibly zero) from the original sequence, leaving the remaining
 * elements in their original order.
 *
 * Given an integer array nums, return the length of the longest wiggle
 * subsequence of nums.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/wiggle-subsequence
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<int>& nums) { return wiggleMaxLength(nums); }

   private:
    int wiggleMaxLength(std::vector<int>& nums) {
        int down = 1, up = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return std::max(down, up);
    }
};

}  // namespace lc

#endif