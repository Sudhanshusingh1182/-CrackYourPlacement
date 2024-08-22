class Solution {
public:
    string reorganizeString(string s) {
        
        int n= s.length();
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;

        for(auto it:s) mp[it]++;

        for(auto it:mp){
           pq.push({it.second,it.first});
        }

        string res="";
        
        if(pq.top().first> (n+1)/2) return "";

        while(!pq.empty()){
           auto [num,ch]= pq.top();
           pq.pop();
           res+=ch;
           
           if(!pq.empty()){
             auto [num2,ch2]=pq.top();
             pq.pop();
             res+=ch2;
             num2--;
             if(num2)
             pq.push({num2,ch2});

           }
           num--;
           if(num)
           pq.push({num,ch});
        }

    return res;
        
    }
};