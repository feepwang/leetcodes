/*
 * 3. 无重复字符的最长子串
 *
 *给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *示例 1:
 *
 *输入: s = "abcabcbb"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *示例 2:
 *
 *输入: s = "bbbbb"
 *输出: 1
 *解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *示例 3:
 *
 *输入: s = "pwwkew"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *示例 4:
 *
 *输入: s = ""
 *输出: 0
 *
 *
 *
 *提示：
 *
 *    0 <= s.length <= 5 * 104
 *    s 由英文字母、数字、符号和空格组成
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
   public:
    int operator()(std::string& s) { return lengthOfLongestSubstring(s); }

    int lengthOfLongestSubstring(std::string s) {
        // 使用滑动窗口，beg、end 表示窗口的头、尾。
        // max_length 保存当前的最大字串长度。
        // 一个哈希表 elems保存窗口中的字符及对应的坐标。
        unsigned beg(0), end(0), max_length(0);
        std::unordered_map<char, unsigned> elems;

        // 遍历字符串
        // 优化性能：当最大子串长度 >
        // 窗口可能达到得到剩余最大子串长度时，跳出循环
        while (end != s.size() && (s.size() - beg) > max_length) {
            // 如果发现重复字符，清理窗口头到重复字符的元素。
            // 窗口头移动到重复字符下一位。
            if (elems.count(s[end])) {
                auto tmp = elems[s[end]] + 1;
                while (beg < tmp) elems.erase(s[beg++]);
            }
            // 插入新的元素
            elems[s[end]] = end;
            // 取当前窗口大小与历史最大值的最大值。
            // 同时窗口尾后移一位
            max_length = std::max(max_length, ++end - beg);
        }
        return max_length;
    }
};

#endif