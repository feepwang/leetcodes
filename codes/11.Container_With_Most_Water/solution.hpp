/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& height) { return maxArea(height); }

    // function()
    int maxArea(vector<int>& height) {
        int area = 0;
        unsigned long i = 0, j = height.size() - 1;
        while (i < j) {
            int tmp_area = (j - i) * min(height[i], height[j]);
            area = max(tmp_area, area);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }

        return area;
    }
};

#endif