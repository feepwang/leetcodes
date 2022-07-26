#include <iostream>

#include "solution.hpp"

struct ListNode;

int main() {
    using namespace std;
    Solution s;

    auto head = new ListNode(3), ptr = head;

    for (int i = 2; i < 6; i++) {
        ptr->next = new ListNode(5);
        ptr = ptr->next;
    }

    head = s(head, 2, 4);

    // print result of solution.
    cout << endl;
}