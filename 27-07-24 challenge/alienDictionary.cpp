#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        // Using Kahn's algorithm 
        vector<int> indegree(V, 0);
        vector<int> ans;
        queue<int> q;
        
        // Calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        // Push nodes with zero indegree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        // Process nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        return ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        // Initialize adjacency list
        vector<vector<int>> adj(k);
        
        // Build the graph
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());
            
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // Get topological sort
        vector<int> topo = topoSort(k, adj);
        
        // Construct the answer string
        string ans = "";
        for (auto it : topo) {
            ans += (it + 'a');
        }
        
        return ans;
    }
};