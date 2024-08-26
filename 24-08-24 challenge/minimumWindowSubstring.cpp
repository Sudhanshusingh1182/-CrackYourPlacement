class Solution {
public:
    // bool checkInMap(string t , unordered_map<char,int>&mp,unordered_map<char,int>&mp2){
    //    bool f=1;
    //    for(auto it:t){
    //      if(mp.find(it)==mp.end()){
    //         f=0;
    //         break;
    //      }

    //      else {
           
    //        if(mp[it]<mp2[it]) return false;
           
    //      }
    //    }

    //    return f;
    // }

    string minWindow(string s, string t) {
         
         int i=0,j=0;
        //  string ans=s;
         bool f=0;
         unordered_map<char,int>mp;
         unordered_map<char,int>mp2;
         int startInd=0;
         int minLen=INT_MAX;
         int formed=0;
         for(auto it:t) mp2[it]++;
         int required= mp2.size();

         while(j<s.length()){
           mp[s[j]]++;

           if (mp2.count(s[j]) && mp[s[j]] == mp2[s[j]]) {
                formed++;
            }

          while(i<=j && formed==required){
             if(j-i+1<minLen){
              minLen=j-i+1;
              startInd=i;
             }

             mp[s[i]]--;

             if (mp2.count(s[i]) && mp[s[i]] < mp2[s[i]]) {
                formed--;
            }

            i++;

          } 

          j++;

         }
          
          return minLen==INT_MAX ? "" : s.substr(startInd,minLen);
         
    }
};