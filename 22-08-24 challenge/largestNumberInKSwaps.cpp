//TC : o(n^k) 
//SC : o(n)

class Solution
{
    public:
    void solve(string str, int k , int ind , string &ans){
        ans= max(ans,str);
        if(k==0) return;
        
        for(int i=ind;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[j]> str[i]){
                    swap(str[i],str[j]);
                    solve(str,k-1,i+1,ans);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(str,k,0,ans);
       return ans;
    }
};