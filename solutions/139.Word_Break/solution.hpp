/*
 * Question
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note that the same word in the dictionary may be reused multiple times in the
 * segmentation.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/word-break
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <set>
#include <string>
#include <vector>

class Solution {
   public:
    // overloading operator()
    bool operator()(const std::string& s, std::vector<std::string>& wordDict) {
        return wordBreak(s, wordDict);
    }

    // function()
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::set<std::string> wordDictSet(wordDict.begin(), wordDict.end());

        std::set<size_t> true_poses{0};
        auto sz = s.size();
        for (size_t i = 1; i <= sz; ++i) {
            for (auto j : true_poses) {
                if (wordDictSet.count(s.substr(j, i - j))) true_poses.insert(i);
            }
        }

        return true_poses.count(sz);
    }
};

#endif