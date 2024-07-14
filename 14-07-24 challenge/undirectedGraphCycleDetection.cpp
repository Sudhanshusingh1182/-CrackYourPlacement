class Solution {
  public:
    bool dfs(int src, int parent , vector<int>&vis, vector<int> adj[]){
        vis[src]=1;
        
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(it,src,vis,adj)) return true;
            }
            
             else if(parent !=it) return true;
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>vis(V+1,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        
        return false;
        
    }
};   