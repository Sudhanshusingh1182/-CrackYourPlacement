class Solution {
  private:
   bool dfs(int node, vector<int>adj[], int vis[], int pathVis[]){
       vis[node]=1;
       pathVis[node]=1;
       
       for(auto it:adj[node]){
           if(!vis[it]){
               if(dfs(it,adj,vis,pathVis)) return true;
           }
           
           else if(pathVis[it]) return true;
       }
       
       pathVis[node]=0;
       return false;
   }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)) return true;
            }
        }
        
        return false;
    }
};


//cycle detection using bfs(Kahn's algorithm)

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // using bfs (Kahn's algorithm)
        
        //kahn's algo -> applicable for dag 
        //if topo sort can't be applied to a graph , it must be cyclic
        
        vector<int>indegree(V,0);
        queue<int>q;
         int cnt=0;
        //populate inorder vector
        for(int i=0;i<V;i++){
            for(auto it: adj[i]) indegree[it]++;
        }
        
        //push the nodes with zero indegree into queue
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
                cnt++;
            }
        }
        
        //keep a count variable to track the no of nodes traversed
       
        while(!q.empty()){
            int ele= q.front();
            q.pop();
            
            
            for(auto it: adj[ele]){
                indegree[it]--;
                if(!indegree[it]) q.push(it), cnt++;
            }
        }
        
        return !(cnt==V);
        
        
    }
};