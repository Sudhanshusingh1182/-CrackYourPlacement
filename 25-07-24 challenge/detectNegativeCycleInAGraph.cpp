class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    //bellman ford algo 
	   vector<int> dist(n);

        for (int i = 0; i < n; ++i) {
            dist.assign(n, INT_MAX);
            dist[i] = 0;

            for (int j = 0; j < n - 1; ++j) {
                for (const auto& edge : edges) {
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];

                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }

            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    return 1;  // Negative weight cycle detected
                }
            }
        }

        return 0;
	        
	}
};