class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V+1]={0};
        
        vector<int>ans;
        
        
        
        queue<int>q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int node= q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return ans;
        
    }
};