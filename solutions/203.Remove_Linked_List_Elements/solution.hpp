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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) head = head->next;
        if (!head) return nullptr;

        ListNode *ptr = head, *tmp;
        while (ptr != nullptr) {
            tmp = ptr->next;
            while (tmp != nullptr && tmp->val == val) tmp = tmp->next;
            ptr->next = tmp;
            ptr = tmp;
        }

        return head;
    }
};

#endif