#include <iostream>

#include "solution.hpp"

struct ListNode;

int main() {
    using namespace std;
    Solution s;

    ListNode *head = new ListNode(1), *ptr = head;
    for (int i = 2; i < 5; i++) {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }

    s(head);

    // print result of solution.
    cout << endl;
}