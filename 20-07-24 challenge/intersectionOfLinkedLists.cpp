/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return nullptr; 
        }

        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA) {
            lenA++;
            tempA = tempA->next;
        }

        while (tempB) {
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if (lenA > lenB) {
            int d = lenA - lenB;
            while (d != 0) {
                tempA = tempA->next;
                d--;
            }
        } else if (lenB > lenA) {
            int d = lenB - lenA;
            while (d != 0) {
                tempB = tempB->next;
                d--;
            }
        }

        while (tempA && tempB) {
            if (tempA == tempB) {
                return tempA; 
            }

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL; 
    }
};