class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //outdegree se dekh rhe h answer ko
        int n= graph.size();
        vector<int>outdegree(n,0), safe(n,0),ans;
        vector<vector<int>>revGraph(n);
        queue<int>q;

        for(int i=0;i<n;i++){
          for(auto it :graph[i]){
             revGraph[it].push_back(i);
          }

          outdegree[i]= graph[i].size();

          if(!outdegree[i]) q.push(i);
        }

        while(!q.empty()){
           int node = q.front();
           safe[node]=1;
           q.pop();

           for(auto it: revGraph[node]){
               outdegree[it]--;

               if(!outdegree[it]) q.push(it);
           }  

        }

        for(int i=0;i<n;i++) {
          if(safe[i]) ans.push_back(i);
        }

        return ans;
    }
};