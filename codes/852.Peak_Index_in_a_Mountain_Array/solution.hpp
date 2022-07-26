/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& arr) { return peakIndexInMountainArray(arr); }

    // function()
    int peakIndexInMountainArray(vector<int>& arr) {
        size_t i = 1, sz = arr.size();
        if (sz == 0 || sz == 1) return 0;
        while (i != sz) {
            if (arr[i - 1] > arr[i]) return i - 1;
            i++;
        }
        return sz - 1;
    }
};

#endif