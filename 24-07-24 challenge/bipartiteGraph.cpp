class Solution {
private:
    bool dfs(int node , vector<int>graph[] , vector<int>&vis ,int currColor){
         vis[node]= currColor;

         for(auto it: graph[node]){
            if(vis[it]== vis[node]) return false;

            if(vis[it]==-1){
               if(!dfs(it,graph,vis, !currColor)) return false;
            }
         }

         return true;
    }  
    
public:
	bool isBipartite(int n, vector<int>graph[]){
	     //we will solve it using dfs

        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){
          if(vis[i]==-1 ){
            if(! dfs(i,graph , vis , 1)) return false;
          } 
        }

        return true;
	    
	}

};