/*
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n]
 * 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次
 * 的整数，并以数组形式返回。
 *
 * 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
 */

#include <vector>

namespace lc {

class Solution {
   public:
    std::vector<int> operator()(std::vector<int>& nums) {
        return findDuplicates(nums);
    }

   private:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> result{};
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            } else {
                result.push_back(x);
            }
        }
        return result;
    }
};

}  // namespace lc
