/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    // overloading operator()
    void operator()(ListNode *head) { reorderList(head); }

    // function()
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // slow = mid
        auto slow = head, fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode *ptr = slow->next, *tail = nullptr;
        while (ptr) {
            auto tmp = ptr->next;
            ptr->next = tail;
            tail = ptr;
            ptr = tmp;
        }
        slow->next = nullptr;

        // merge
        auto l1 = head, l2 = tail;
        while (l2) {
            auto t1 = l1->next, t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1, l2 = t2;
        }
    }
};

#endif