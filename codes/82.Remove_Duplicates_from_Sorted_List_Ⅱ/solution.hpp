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
    //
    ListNode* operator()(ListNode* head) { return deleteDuplicates(head); }

   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto head_ptr = new ListNode(head->val - 1, head), tail = head->next;
        auto ptr = head_ptr;
        while (tail != nullptr) {
            if (ptr->next->val != tail->val) {
                ptr = ptr->next;
                tail = tail->next;
            } else {
                while (tail != nullptr && ptr->next->val == tail->val)
                    tail = tail->next;
                if (tail == nullptr)
                    ptr->next = nullptr;
                else {
                    ptr->next = tail;
                    tail = tail->next;
                }
            }
        }

        return head_ptr->next;
    }
};

#endif