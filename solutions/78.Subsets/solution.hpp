/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cstddef>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    vector<vector<int>> operator()(vector<int>& nums) { return subsets(nums); }

    // function()
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{vector<int>{}};
        for (const auto& a : nums) {
            size_t sz = result.size();
            for (size_t i = 0; i < sz; ++i) {
                vector<int> tmp{result[i]};
                tmp.push_back(a);
                result.push_back(tmp);
            }
        }

        return result;
    }
};

#endif