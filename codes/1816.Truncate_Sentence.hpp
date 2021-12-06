/*
 * Question:
 * A sentence is a list of words that are separated by a single space with no
 * leading or trailing spaces. Each of the words consists of only uppercase and
 * lowercase English letters (no punctuation).
 *
 * For example, "Hello World", "HELLO", and "hello world hello world" are all
 * sentences. You are given a sentence s​​​​​​ and an integer
 * k​​​​​​. You want to truncate s​​​​​​ such that it
 * contains only the first k​​​​​​ words. Return s​​​​​​
 * after truncating it.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/truncate-sentence
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>

namespace lc {

class Solution {
   public:
    std::string operator()(const std::string& s, int k) {
        return truncateSentence(s, k);
    }

   private:
    std::string truncateSentence(std::string s, int k) {
        int cur = 0;
        while (k && cur < s.size()) {
            if (s[++cur] == ' ') k--;
        }
        return s.substr(0, cur);
    }
};

}  // namespace lc

#endif