class Solution
{   private:
    void dfsFill(int node ,vector<vector<int>>& adj ,vector<bool>&vis , stack<int>& st){
         vis[node]=1;
         
         for(auto it: adj[node]){
             if(!vis[it])  dfsFill(it,adj,vis,st);
         }
         
         st.push(node);
    }
    
    void dfs(int node ,vector<vector<int>> &reversedGraph, vector<bool>&vis){
         
         vis[node]=1;
         
         for(auto it: reversedGraph[node]){
             if(!vis[it]) dfs(it,reversedGraph,vis);
         }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        //s-1 : Find the ordering in which we will traverse the graph
        //It is basically topological sort
        stack<int>st;
        vector<bool>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsFill(i,adj,vis ,st);
            }
        }
        
        //s-2 : Reverse the graph 
        
        vector<vector<int>> reversedGraph(V);
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]) reversedGraph[it].push_back(i);
        }
        
        //s-3 :count the strongly connected components
        int cntScc=0;
        vis = vector<bool>(V,0);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs(node ,reversedGraph , vis);
                cntScc++;
            }
        }
        
        return cntScc;
    }
};