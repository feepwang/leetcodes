/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cstddef>
#include <unordered_map>

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    // overloading operator()
    Node* operator()(Node* head) { return copyRandomList(head); }

    // function()
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random =
                (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next =
                (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
    // Node* copyRandomList(Node* head) {
    //     if (!head) return NULL;

    //     unordered_map<int, Node*> hash;
    //     Node* traverser = head;

    //     Node* result = new Node(0);
    //     Node* creater = result;

    //     while (traverser) {
    //         creater->next = new Node(traverser->val);
    //         creater = creater->next;

    //         hash.insert({traverser->val, creater});
    //         traverser = traverser->next;
    //     }

    //     traverser = head;
    //     creater = traverser->next;
    //     while (traverser != NULL) {
    //         creater->random =
    //             traverser->random ? hash[traverser->random->val] : NULL;
    //         traverser = traverser->next;
    //         creater = creater->next;
    //     }

    //     return result->next;
    // }
};

#endif