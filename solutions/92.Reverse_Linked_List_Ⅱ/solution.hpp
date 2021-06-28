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
    ListNode* operator()(ListNode* head, int left, int right) {
        return reverseBetween(head, left, right);
    }

    // function()
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto head_ptr = new ListNode(0, head);

        //  找到指向起始位置的节点和尾后节点
        ListNode *left_ptr = head_ptr, *right_next = head;
        while (--left && right_next != nullptr) {
            left_ptr = left_ptr->next;
            right_next = right_next->next;
            right--;
        }
        while (right-- && right_next != nullptr) right_next = right_next->next;

        auto front = left_ptr->next, behind = right_next;
        while (front != right_next) {
            auto tmp = front->next;
            front->next = behind;
            behind = front;
            front = tmp;
        }
        left_ptr->next = behind;
        return head_ptr->next;
    }
};

#endif