//TOPO SORT USING DFS

class Solution
{   
    private:
    void dfs(int node , vector<int>adj[], vector<int>&vis , stack<int>&st){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it,adj,vis,st);
            
        }
        
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    
	    stack<int>st;
	    
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	        dfs(i,adj,vis,st);
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};

//TOPO SORT USING BFS (KAHN'S ALGORITHM)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   //using Kahn's algorithm
	   vector<int>indegree(V,0);
	   queue<int>q;
	   vector<int>ans;
	   
	   //populate indegree wala vector
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]) indegree[it]++;
	   }
	   
	   
	   //jiska indegree 0 hai usko queue me push krenge 
	   
	   for(int i=0;i<V;i++) if(!indegree[i]) q.push(i);
	   
	   //bfs call krenge 
	   
	   while(!q.empty()){
	       int ele = q.front();
	       q.pop();
	       ans.push_back(ele);
	       
	       for(auto it:adj[ele]){
	           indegree[it]--;
	           
	           if(!indegree[it]) q.push(it);
	       }
	   }
	   
	   //answer return krenge
	   return ans;
	   
	}
};