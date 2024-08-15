/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        // Pointer
        Node* p = head;

        while (p != nullptr) {
            /* CASE 1: if no child, proceed */
            if (p->child == nullptr) {
                p = p->next;
                continue;
            }

            /* CASE 2: got child, find the tail of the child and link it to p->next */
            Node* temp = p->child;

            // Find the tail of the child
            while (temp->next != nullptr)
                temp = temp->next;

            // Connect tail with p->next, if it is not null
            temp->next = p->next;
            if (p->next != nullptr)
                p->next->prev = temp;

            // Connect p with p->child, and remove p->child
            p->next = p->child;
            p->child->prev = p;
            p->child = nullptr;
        }

        return head;
    }
};
