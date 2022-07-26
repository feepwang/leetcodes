/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    int singleNumber(vector<int>& nums) {
        unordered_map<int, size_t> hash;
        for (auto i : nums) {
            if (hash.count(i))
                hash[i]++;
            else
                hash[i] = 1;
        }

        int result;
        for (auto p : hash) {
            if (p.second == 1) {
                result = p.first;
                break;
            }
        }

        return result;
    }
};

#endif