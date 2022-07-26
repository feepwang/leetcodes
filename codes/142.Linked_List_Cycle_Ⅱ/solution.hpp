/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    ListNode *detectCycle(ListNode *head) {}
};

#endif