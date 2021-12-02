/*
 * Question:
 * You are given an integer array score of size n, where score[i] is the score
 * of the ith athlete in a competition. All the scores are guaranteed to be
 * unique.
 *
 * The athletes are placed based on their scores, where the 1st place athlete
 * has the highest score, the 2nd place athlete has the 2nd highest score, and
 * so on. The placement of each athlete determines their rank:
 *
 * The 1st place athlete's rank is "Gold Medal".
 * The 2nd place athlete's rank is "Silver Medal".
 * The 3rd place athlete's rank is "Bronze Medal".
 * For the 4th place to the nth place athlete, their rank is their placement
 * number (i.e., the xth place athlete's rank is "x"). Return an array answer of
 * size n where answer[i] is the rank of the ith athlete.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/relative-ranks
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace lc {

class Solution {
   public:
    std::vector<std::string> operator()(std::vector<int>& score) {
        return findRelativeRanks(score);
    }

   private:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> result(score.size());
        std::map<int, size_t, std::greater<>> index{};
        for (size_t i = 0; i < score.size(); ++i) index.insert({score[i], i});

        auto beg = index.cbegin(), end = index.cend();
        if (index.size() > 3) {
            result[beg++->second] = "Gold Medal";
            result[beg++->second] = "Silver Medal";
            result[beg++->second] = "Bronze Medal";
            int i = 4;
            while (beg != end) {
                result[beg++->second] = std::move(std::to_string(i++));
            }
        } else {
            if (beg != end) result[beg++->second] = "Gold Medal";
            if (beg != end) result[beg++->second] = "Silver Medal";
            if (beg != end) result[beg++->second] = "Bronze Medal";
        }
        return result;
    }
};

}  // namespace lc

#endif