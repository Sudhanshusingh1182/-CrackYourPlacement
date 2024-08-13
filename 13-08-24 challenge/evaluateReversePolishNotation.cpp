class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;

        int ans=0;
        for(int i=0;i<n;i++){
            if(tokens[i].length() ==1 && (tokens[i][0]<'0' || tokens[i][0]>'9')){
               //character hai 
               if(st.size()>=2){
                 int num1 = st.top(); st.pop();
                 int num2= st.top(); st.pop();
                 int temp;
                 char ch = tokens[i][0];
                 switch(ch){
                  case '+' :  temp = num1+ num2;break;

                  case '-': temp = num2-num1;break;

                  case '*' : temp = num2*num1;break;

                  case '/' : temp = num2/num1;break;
                 }

                 st.push(temp);
               }
            }

            else{
              st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};