class Solution {
public:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    void dfs(int r, int c, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        vis[r][c] = true;
        q.push({r, c});

        for (int i = 0; i < 4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];

            // DFS should work on land cells (1) to mark them and push to queue
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && !vis[newr][newc]) {
                dfs(newr, newc, n, m, vis, grid, q);
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        // DFS to mark all land cells and push their positions into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, n, m, vis, grid, q);
                }
            }
        }

        // If there are no water cells or no land cells, return -1 (invalid scenario)
        if (q.empty() || q.size() == n * m) {
            return -1;
        }

        int maxi = -1; // Maximum distance
        while (!q.empty()) {
            int sz = q.size();
            maxi++; // Increase distance level each time we process a layer

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newr = r + dr[j];
                    int newc = c + dc[j];

                    // Spread BFS over water cells (0) only
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && !vis[newr][newc]) {
                        vis[newr][newc] = true; // Mark as visited
                        q.push({newr, newc});
                    }
                }
            }
        }

        return maxi; // Return maximum distance found
    }
};
