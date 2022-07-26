/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::min;
#include <stack>
using std::stack;

class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (minstack.empty())
            push(val);
        else
            minstack.push(min(val, minstack.top()));
    }

    void pop() {
        stk.pop();
        minstack.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return minstack.top(); }

   private:
    stack<int> stk, minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    // int add(int i,int j);
};

#endif