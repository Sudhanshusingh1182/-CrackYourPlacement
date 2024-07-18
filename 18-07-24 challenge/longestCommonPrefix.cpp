class Solution {
private:
   int checkAns(string s, string t){
    int i=0,j=0;
    int cnt=0;
    while(i<s.length() && j<t.length()){
       if(s[i]==t[j]){
        cnt++;
        i++,j++;
       }

       else break;
    }

    return cnt;
   }  
public:
    string longestCommonPrefix(vector<string>& str) {
        string temp="";
        int n= str.size();
        int maxi=str[0].length();
        for(int i=1;i<n;i++){
            int ans= checkAns(str[0], str[i]);
            maxi=min(maxi,ans);
        }

        return maxi==0 ? "" : str[0].substr(0,maxi);
    }
};