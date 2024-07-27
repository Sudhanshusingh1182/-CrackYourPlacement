class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        
        stack<int>st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                st.push(s[i]-'0');
            }
            
            else{
                int top1= st.top();
                st.pop();
                int top2= st.top();
                st.pop();
                
                char ch = s[i];
                switch (ch){
                
                case '+' : 
                   st.push(top1 + top2);
                   break;
                   
                case '-' :
                   st.push(top2-top1);
                   break;
                   
                case '*':
                   st.push(top2*top1);
                   break;
                   
                case '/':
                   st.push(top2/top1);
                   break;
                }
            }
        }
        
        return st.top();
        
        
    }
};    