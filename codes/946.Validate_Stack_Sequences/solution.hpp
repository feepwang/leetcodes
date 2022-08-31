/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <stack>
using std::stack;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0;
        std::stack<int> s;
        for (int p : pushed) {
            s.push(p);
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                ++i;
            }
        }
        return i == n;
    }
};

#endif
