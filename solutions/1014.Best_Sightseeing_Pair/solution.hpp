/*
 * Question
 * You are given an integer array values where values[i] represents the value of
 * the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i
 * between them.
 *
 * The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i
 * - j: the sum of the values of the sightseeing spots, minus the distance
 * between them.
 *
 * Return the maximum score of a pair of sightseeing spots.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/best-sightseeing-pair
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& values) {
        return maxScoreSightseeingPair(values);
    }

    // function()
    int maxScoreSightseeingPair(vector<int>& values) {
        int result{values[0]}, pole{};
        for (int sz = values.size(), i = 1; i < sz; ++i) {
            auto val1 = values[pole], val2 = values[i], val3 = pole - i;
            result = std::max(result, val1 + val2 + val3);
            pole = (val2 - val1) >= val3 ? i : pole;
        }
        return result;
    }
    // int maxScoreSightseeingPair(vector<int>& values) {
    //     int pos = values[0] > values[1] ? 0 : 1;
    //     int result = values[0] + values[1] - 1;
    //     for (int i = 2, sz = values.size(), tmp{0}; i < sz; i++) {
    //         tmp = pos - i + values[pos] + values[i];
    //         if ((values[pos] - values[i]) < (i - pos)) pos = i;
    //         if (result < tmp) result = tmp;
    //     }
    //     return result;
    // }
};

#endif