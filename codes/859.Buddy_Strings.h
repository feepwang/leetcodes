/*
 * Question:
 * Given two strings s and goal, return true if you can swap two letters in s so
 * the result is equal to goal, otherwise, return false.
 *
 * Swapping letters is defined as taking two indices i and j (0-indexed) such
 * that i != j and swapping the characters at s[i] and s[j].
 *
 * For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/buddy-strings
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>
#include <vector>

namespace lc {

class Solution {
   public:
    bool operator()(const std::string& s, const std::string& goal) {
        return buddyStrings(s, goal);
    }

   private:
    bool buddyStrings(std::string s, std::string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal) {
            std::vector<int> count(26);
            for (size_t i = 0, size = s.size(); i < size; ++i) {
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            int first = -1, second = -1;
            for (size_t i = 0, size = s.size(); i < size; ++i) {
                if (s[i] != goal[i]) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }
            return (second != -1 && s[first] == goal[second] &&
                    s[second] == goal[first]);
        }
    }
};

}  // namespace lc

#endif