class Solution {
public:
    double solve(string src, string des, unordered_map<string, vector<pair<string, double>>>& adj, set<string>& visited) {
        if (src == des) return 1.0;
        
        visited.insert(src); // Mark the current node as visited

        for (auto& it : adj[src]) {
            string nextNode = it.first;
            double edgeWeight = it.second;

            if (visited.find(nextNode) == visited.end()) {
                double productWeight = solve(nextNode, des, adj, visited);
                if (productWeight != -1) { // Check if a valid path was found
                    return edgeWeight * productWeight;
                }
            }
        }

        return -1.0; // If no valid path found, return -1
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        // Create the adjacency list
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < n; i++) {
            string str1 = equations[i][0];
            string str2 = equations[i][1];
            double val = values[i];

            adj[str1].emplace_back(str2, val);
            adj[str2].emplace_back(str1, 1 / val);
        }

        vector<double> ans;
        // Solve for each query
        for (int i = 0; i < queries.size(); i++) {
            string src = queries[i][0];
            string des = queries[i][1];
            
            if (adj.find(src) == adj.end() || adj.find(des) == adj.end()) {
                ans.push_back(-1.0); // If either src or des does not exist in the graph
            } else {
                set<string> visited;
                double res = solve(src, des, adj, visited);
                ans.push_back(res);
            }
        }

        return ans;
    }
};