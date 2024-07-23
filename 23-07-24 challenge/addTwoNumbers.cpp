/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *solve(ListNode *head1, ListNode *head2) {
    int sum = 0, carry = 0;
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;

    while (temp1->next && temp2->next) {
        sum = temp1->val + temp2->val + carry;
        temp1->val = sum % 10;
        carry = sum / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    sum = temp1->val + temp2->val + carry;
    temp1->val = sum % 10;
    carry = sum / 10;

    if (temp1->next) {
        temp1 = temp1->next;
        while (temp1->next) {
            sum = temp1->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;
            temp1 = temp1->next;
        }

        sum = temp1->val + carry;
        temp1->val = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        ListNode *carryNode = new ListNode(carry);
        temp1->next = carryNode;
    }

    return head1;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;

    if (l1 == NULL && l2 != NULL) return l2;

    if (l1 != NULL && l2 == NULL) return l1;

    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    int len1 = 0, len2 = 0;

    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 >= len2)   return solve(l1, l2);
     else  return solve(l2, l1);
    }
};