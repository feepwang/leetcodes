#include <iostream>

#include "solution.hpp"

struct ListNode;

int main() {
    using namespace std;
    Solution s;

    auto head = new ListNode(1), tail = head;
    for (int i = 2; i < 6; i++) {
        tail->next = new ListNode(i);
        tail = tail->next;
    }

    // print result of solution.
    auto output = s(head, 2);
    for (auto tmp = output; tmp != nullptr; tmp = tmp->next)
        cout << tmp->val << ' ';

    cout << endl;
}