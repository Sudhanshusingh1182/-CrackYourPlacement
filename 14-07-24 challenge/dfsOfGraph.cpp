class Solution {
  private:
    void dfs(int node, vector<int>&ans, int vis[], vector<int> adj[]){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,ans,vis,adj);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        int vis[V+1]={0};
        
        dfs(0,ans,vis,adj);
        
        return ans;
    }
};