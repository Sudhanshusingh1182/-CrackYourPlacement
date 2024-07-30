class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string &st, int s, int e){
       
       while(s<e){
         if(st[s]!=st[e]) return false;

         s++,e--;
       }

       return true;
    }

    void f(int ind, int n,string &s, vector<string>&temp){
       if(ind==n){
        ans.push_back(temp);
        return;
       }

       for(int k=ind;k<n;k++){
        if(isPalindrome(s,ind,k)){
          temp.push_back(s.substr(ind,k-ind+1));
          f(k+1,n,s,temp);
          temp.pop_back();
        }
       }
    }

    vector<vector<string>> partition(string s) {
        if(s.length()==1) return {{s}};
        
        vector<string>temp;

        f(0,s.length(),s,temp);
        
        return ans;
    }
};