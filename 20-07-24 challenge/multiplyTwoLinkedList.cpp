class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long mod= 1e9 + 7;
        long long num1=0;
        long long num2=0;
        
        while(first!=NULL){
            num1= (num1*10)%mod + first->data;
            first=first->next;
        }
        
        while(second!=NULL){
            num2= (num2*10)%mod + second->data;
            second= second->next;
        }
        
        return (num1*num2)%mod;
        
    }
};