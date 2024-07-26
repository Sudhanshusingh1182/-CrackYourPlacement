class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,1e9+7));
        
        for(int i=0;i<n;i++) dist[i][i]=0;

        for(auto it:edges){
           int u= it[0];
           int v= it[1];
           int wt= it[2];

           dist[u][v]=wt;
           dist[v][u]=wt;
        }

        //apply the floyd Warshal Algorithm

        for(int via=0;via<n;via++){
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               dist[i][j] = min(dist[i][j], dist[i][via]+ dist[via][j]);
            }
          }
        }

        int node=-1, miniCnt = INT_MAX;

        for(int i=0;i<n;i++){
          int sum=0;
          for(int j=0;j<n;j++){
             if(i!=j && dist[i][j]<= distanceThreshold) sum++;
          } 

          if(sum<= miniCnt) {
             miniCnt = sum;
             node= i;
          }
        }
        
        return node;

    }
};