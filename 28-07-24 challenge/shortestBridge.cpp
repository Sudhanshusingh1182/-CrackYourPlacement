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

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && !vis[newr][newc]) {
                dfs(newr, newc, n, m, vis, grid, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        // DFS to find and mark all 1s of the first island
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (found) break;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, n, m, vis, grid, q);
                    found = true; // Found and marked the first island
                    break;
                }
            }
        }

        // BFS to find the shortest path to the second island
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int newr = r + dr[j];
                    int newc = c + dc[j];

                    if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc]) {
                        if (grid[newr][newc] == 1) {
                            return cnt; // Found the second island
                        }
                        vis[newr][newc] = true;
                        q.push({newr, newc});
                    }
                }
            }
            cnt++;
        }

        return -1; // Should never reach here if there's always a path
    }
};
