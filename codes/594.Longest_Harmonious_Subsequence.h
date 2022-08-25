/*
 * Question:
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 *
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/longest-harmonious-subsequence
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <unordered_map>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<int>& nums) { return findLHS(nums); }

   private:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto i : nums) {
            ++map[i];
        }
        int result{};
        for (auto p : map) {
            if (map.count(p.first + 1)) {
                result = std::max(result, p.second + map[p.first]);
            }
        }
        return result;
    }
};

}  // namespace lc

#endif