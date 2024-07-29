class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>st;
        string ans;
        int n= path.length();
        string temp;

        for(int i=0;i<n;i++){
          if(path[i]=='/') continue;
   
          temp.clear();
          while(i<n && path[i]!='/'){
            temp+=path[i];
            i++;
          }

          if(temp ==".") continue;

          else if(temp==".."){
            if(!st.empty()) st.pop();
          }

          else st.push(temp);
        }

        if(st.empty()) return "/";

        while(!st.empty()){
           ans= '/'+ st.top()+ ans;
           st.pop();
        }
        
        return ans;

    }
};