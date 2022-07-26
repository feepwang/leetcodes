/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return longestConsecutive(nums); }

    // function()

    int find(int x, unordered_map<int, int>& hash) {
        return hash.count(x) ? hash[x] = find(hash[x], hash) : x;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto i : nums) hash[i] = i + 1;
        int result;
        for (auto i : nums) {
            int j = find(i + 1, hash);
            result = std::max(j - i, result);
        }
        return result;
    }
};

#endif