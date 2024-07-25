class Solution
{
	public:
	typedef pair<int,int> p;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        priority_queue<p,vector<p>,greater<p>>pq;
        
        vector<bool>vis(V,0);
        
        int sum=0;
        
        pq.push({0,0}); //wt-node
        
        while(!pq.empty()){
            auto top = pq.top();
            int wt = top.first;
            int node= top.second;
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int nbr = it[0];
                int nbr_wt = it[1];
                
                pq.push({nbr_wt , nbr});
            }
        }
        
        return sum;
        
    }
};