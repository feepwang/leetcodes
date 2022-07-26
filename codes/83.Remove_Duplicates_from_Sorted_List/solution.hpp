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
    ListNode* operator()(ListNode* head) { return deleteDuplicates(head); }

    // function()
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        auto ptr = head;
        while (ptr->next != nullptr) {
            if (ptr->val == ptr->next->val) {
                auto tmp = ptr->next;
                ptr->next = tmp->next;
                delete tmp;
            } else
                ptr = ptr->next;
        }
        return head;
    }
};

#endif