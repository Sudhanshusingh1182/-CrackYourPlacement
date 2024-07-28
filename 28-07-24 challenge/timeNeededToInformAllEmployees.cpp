class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
              if(manager[i]!=-1)
              adj[manager[i]].push_back(i);
           
        }
        
        int maxi = 0;
        queue<pair<int,int>>q; // ID , time
        q.push({headID, 0}); 
        while(!q.empty()){
           int sz= q.size();

           for(int i=0;i<sz;i++){
             int node = q.front().first;
             int t =q.front().second;
             q.pop();

             int dur = informTime[node]+ t;
             maxi= max(maxi,dur);

             for(auto it:adj[node]){
               q.push({it,dur});
             }
           } 

        }

        return maxi;
    }
};