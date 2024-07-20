class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1="";
        string str2="";

        stack<char>st1;
        stack<char>st2;

        for(int i=0;i<s.length();i++){
          if(s[i]!='#') st1.push(s[i]);

          else if(!st1.empty()) st1.pop();
        }

        for(int i=0;i<t.length();i++){
          if(t[i]!='#') st2.push(t[i]);

          else if(!st2.empty()) st2.pop();
        }

        while(!st1.empty()){
            str1+= st1.top();
            st1.pop();
        }

        while(!st2.empty()){
          str2+= st2.top();
          st2.pop();
        }

        return str1==str2;

    }
};