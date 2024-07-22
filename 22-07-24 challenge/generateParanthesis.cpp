class Solution {
public:
    void f(int i,int j,int n, string & temp , vector<string>&ans){
      if(i==n && j==n){
        ans.push_back(temp);
        return ;
      }

      // two possibilities : open bracket and close bracket 

      //open bracket
      if(i+1<=n){
        temp.push_back('(');
        f(i+1,j,n,temp,ans);
        temp.pop_back();
      }

      //closing bracket
      if(j+1<=n && j+1<=i){
        temp.push_back(')');
        f(i,j+1,n,temp,ans);
        temp.pop_back();
      }
    }
    
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      int i=0,j=0; // i represents the no of opening bracket
      //and j represnts the no of closing bracket
      
      string temp;

      f(0,0,n,temp,ans);

      return ans;
    }
};