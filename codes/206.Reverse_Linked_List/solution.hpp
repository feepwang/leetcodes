/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        while (head != nullptr) {
            auto tmp = head->next;
            head->next = tail;
            tail = head;
            head = tmp;
        }
        return tail;
    }
};

#endif