class Solution {
  public:
   Node *reverse(Node *root)
{
    
    Node *prev = NULL;
    Node *curr = root;
    while(root!=NULL)
    {
        curr = root;
        root = root->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

Node *inPlace(Node *root)
{
    Node *fast = root;
    Node *slow = root;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head1 = root;
    Node *head2 = slow->next;
    head2 = reverse(head2);
    slow->next = NULL;
    
    
    Node *head = new Node(0);
    Node* curr = head;
    while (head1 || head2) {
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    return head->next;
 }
};