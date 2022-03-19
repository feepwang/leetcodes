/*
 * Question:
 * 给出一个字符串数组 words 组成的一本英语词典。返回 words
 * 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
 *
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/longest-word-in-dictionary
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace lc {

class Solution {
   public:
    std::string operator()(std::vector<std::string>& words) {
        return longestWord(words);
    }

   private:
    std::string longestWord(std::vector<std::string>& words) {
        std::sort(words.begin(), words.end(),
                  [](const std::string& a, const std::string& b) {
                      return a.size() != b.size() ? a.size() < b.size() : a > b;
                  });

        std::string longest;
        std::unordered_set<std::string> candidates = {""};
        for (const auto& word : words) {
            if (candidates.count(word.substr(0, word.size() - 1))) {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};

}  // namespace lc