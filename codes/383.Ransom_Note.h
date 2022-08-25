/*
 * Question:
 * Given two stings ransomNote and magazine, return true if ransomNote can be
 * constructed from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/ransom-note
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <map>
#include <string>

namespace lc {

class Solution {
   public:
    bool operator()(const std::string& ransomNote,
                    const std::string& magazine) {
        return canConstruct(ransomNote, magazine);
    }

   private:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::map<char, size_t> ransome{}, maga{};
        for (auto c : ransomNote) ransome[c]++;
        for (auto c : magazine) maga[c]++;
        for (auto p : ransome) {
            if (maga.count(p.first)) {
                if (maga[p.first] < p.second) return false;
            } else
                return false;
        }
        return true;
    }
};

}  // namespace lc

#endif