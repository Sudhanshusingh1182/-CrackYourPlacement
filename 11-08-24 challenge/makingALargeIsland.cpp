class Solution {
public:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& label, int n, int m, int componentLabel) {
        int size = 1;
        label[r][c] = componentLabel;

        for (int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && label[newr][newc] == 0) {
                size += dfs(newr, newc, grid, label, n, m, componentLabel);
            }
        }

        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> label(n, vector<int>(m, 0));
        unordered_map<int, int> componentSize;
        int componentLabel = 1;
        int maxIslandSize = 0;

        // Label each component and calculate its size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && label[i][j] == 0) {
                    int size = dfs(i, j, grid, label, n, m, componentLabel);
                    componentSize[componentLabel] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    componentLabel++;
                }
            }
        }

        // Try flipping each 0 to 1 and calculate the potential island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seenLabels;
                    int potentialIslandSize = 1;

                    // Check all 4 directions
                    for (int k = 0; k < 4; k++) {
                        int newr = i + dr[k];
                        int newc = j + dc[k];

                        if (newr >= 0 && newr < n && newc >= 0 && newc < m && label[newr][newc] > 0) {
                            int compLabel = label[newr][newc];
                            if (seenLabels.find(compLabel) == seenLabels.end()) {
                                potentialIslandSize += componentSize[compLabel];
                                seenLabels.insert(compLabel);
                            }
                        }
                    }

                    maxIslandSize = max(maxIslandSize, potentialIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};
