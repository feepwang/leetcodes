/*
 * Question:
 * Given an integer array nums, design an algorithm to randomly shuffle the
 * array. All permutations of the array should be equally likely as a result of
 * the shuffling.
 *
 * Implement the Solution class:
 *
 * Solution(int[] nums) Initializes the object with the integer array nums.
 * int[] reset() Resets the array to its original configuration and returns it.
 * int[] shuffle() Returns a random shuffling of the array.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/shuffle-an-array
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP
#define LC_SOLUTION_HPP

#include <algorithm>
#include <ostream>
#include <vector>

namespace lc {

class Solution {
    friend std::ostream& operator<<(std::ostream& os, const Solution& sol);

   public:
    Solution(const std::vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    std::vector<int> reset() {
        std::copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    std::vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }

   private:
    std::vector<int> nums;
    std::vector<int> original;
};

std::ostream& operator<<(std::ostream& os, const Solution& sol) {
    for (auto i : sol.nums) {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

}  // namespace lc

#endif