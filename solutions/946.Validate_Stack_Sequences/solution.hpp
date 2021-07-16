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
        stack<int> stk;

        int i = 0, sz = popped.size();
        for (const auto& a : pushed) {
            stk.push(a);
            while (i < sz && stk.top() == popped[a]) {
                i++;
                stk.pop();
            }
        }

        return i == sz;
    }
};

#endif