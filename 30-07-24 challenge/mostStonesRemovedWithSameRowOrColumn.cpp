class Solution {
public:
    vector<int> parent;

    // Find the root of the component for stone x with path compression
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    // Union two stones by connecting their roots
    void Union(int x, int y) {
        int u = findParent(x);
        int v = findParent(y);

        if (u == v) return;

        parent[u] = v;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // Define n as the number of stones
        parent.resize(n);

        // Initialize each stone to be its own parent
        iota(parent.begin(), parent.end(), 0);

        // Connect stones that are in the same row or column
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }

        int noOfComponents = 0;

        // Count the number of unique components
        for (int i = 0; i < stones.size(); i++) {
            if (parent[i] == i) noOfComponents++;
        }

        // The number of stones that can be removed is total stones minus number of components
        return stones.size() - noOfComponents;
    }

};