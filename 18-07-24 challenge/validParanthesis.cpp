class Solution {
public:
    bool isValid(string s) {
        
        int n= s.length();
        stack<char>st;

        for(int i=0;i<n;i++){
           if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);

           else{
             if(!st.empty()){
                char top= st.top();
                
                if((s[i]==')' && top=='(') || (s[i]=='}' && top=='{') ||(s[i]==']' && top=='['))
                  st.pop();
                
                else return false;
             }

              else  return false;
           }

        }

        return st.empty();
    }
};