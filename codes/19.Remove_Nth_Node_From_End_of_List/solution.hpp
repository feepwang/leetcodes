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
    ListNode* operator()(ListNode* head, const int& n) {
        return removeNthFromEnd(head, n);
    }

    // function()
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head, *ptr = head;
        //  建立一个窗口，tail - ptr = n
        while (n--) {
            if (tail == nullptr) return head;
            tail = tail->next;
        }
        if (tail == nullptr) return head->next;

        // 当 tail指向最后一个节点时，ptr指向目标节点的上一位
        while (tail->next != nullptr) {
            tail = tail->next;
            ptr = ptr->next;
        }

        auto tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;

        return head;
    }
};

#endif