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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            slow = slow->next;
            for (int i = 0; i < 2; i++) {
                fast = fast->next;
                if (fast == nullptr) return false;
            }
        }

        return true;
    }
};

#endif