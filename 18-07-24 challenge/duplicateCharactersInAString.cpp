class Solution
{
  public:
    char firstRep (string s)
    {
        unordered_map<char,int>mp;
        
        for(auto it:s) mp[it]++;
        
        char ans='#';
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]>1) {
                ans=s[i];
                break;
            }
        }
        
        return ans;
    }
};