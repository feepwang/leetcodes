/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cmath>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    vector<int> operator()(const int& area) { return constructRectangle(area); }

    // function()
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int w = sqrt(area);
        while (area % w != 0) {
            w--;
        }
        result.push_back(area / w);
        result.push_back(w);
        return result;
    }
};

#endif