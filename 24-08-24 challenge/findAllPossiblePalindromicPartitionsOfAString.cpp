class Solution {
  public:
     bool f(int i,int j,string &s){
        if(i>=j)
            return true;
        if(s[i]!=s[j])
            return false;
        return f(i+1,j-1,s);
        
    }
    
    
    bool isP(string &s){
        int i=0;
        int j=s.size()-1;
        
        return f(i,j,s);
        
    }
    
    void fun(int i,string &s,vector<vector<string>> &ans,vector<string> &p){
        if(i>=s.size()){
            ans.push_back(p);
            return;
        }
        string t="";
        for(int k=i;k<s.size();k++){
            t+=s[k];
            if(isP(t)){
                p.push_back(t);
                fun(k+1,s,ans,p);
                p.pop_back();
                
            }
        }
        return;
    }
    
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> p;
    
        fun(0,S,ans,p);
        return ans;
    }
};