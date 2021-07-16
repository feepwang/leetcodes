/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hash;
        for (auto i : deliciousness) hash[i]++;
    }
};

#endif