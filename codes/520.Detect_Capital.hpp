/*
 * Question
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * Given a string word, return true if the usage of capitals in it is right.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/detect-capital
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <cctype>
#include <string>

namespace lc {

class Solution {
   public:
    // override operator()
    bool operator()(const std::string& word) { return detectCapitalUse(word); }

   private:
    // function
    bool detectCapitalUse(std::string word) {
        auto sz = word.size();
        if (1 == sz) return true;
        // if (std::isupper(word[0])) {
        //     if (std::isupper(word[1])) {
        //         for (int i = 2; i < sz; ++i) {
        //             if (std::islower(word[i])) return false;
        //         }
        //     } else {
        //         for (int i = 2; i < sz; ++i) {
        //             if (std::isupper(word[i])) return false;
        //         }
        //     }
        // } else {
        //     for (int i = 1; i < sz; ++i) {
        //         if (std::isupper(word[i])) return false;
        //     }
        // }

        if (std::isupper(word[0]) && std::isupper(word[1])) {
            for (int i = 2; i < sz; ++i) {
                if (std::islower(word[i])) return false;
            }
        } else {
            for (decltype(sz) i = std::isupper(word[0]) ? 2 : 1; i < sz; ++i) {
                if (std::isupper(word[i])) return false;
            }
        }

        return true;
    }
};

}  // namespace lc

#endif  // LC_SOLUTION_HPP_