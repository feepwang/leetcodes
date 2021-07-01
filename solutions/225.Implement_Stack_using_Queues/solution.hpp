/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <queue>
using std::queue;

class MyStack {
    queue<int> que1, que2;

   public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        que2.push(x);
        while (!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1, que2);
    }

    /** Removes the element on top of the stack and returns that element.
     */
    int pop() {
        auto tmp = que1.front();
        que1.pop();
        return tmp;
    }

    /** Get the top element. */
    int top() { return que1.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return que1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#endif