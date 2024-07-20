class Solution
{
    public:
    Node *compute(Node *head)
    {
        
        //recursive approach 
        
        if (!head->next)
            return head;
        head->next=compute(head->next);
        return (head->data < head->next->data)?head->next:head;
    }
    
};