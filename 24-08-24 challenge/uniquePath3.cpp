class Solution {
private:
    int cnt = 0; // To count the number of unique paths

    bool issafe(int x, int y, int endrow, int endcol, vector<vector<int>>& grid, vector<vector<int>> &vist) {
        // Check boundaries and if the cell is not an obstacle or already visited
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] != -1 && !vist[x][y]);
    }

    pair<int, int> find_start(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) return {i, j}; // Start point
            }
        }
        return {-1, -1}; // Not found
    }

    pair<int, int> find_end(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) return {i, j}; // End point
            }
        }
        return {-1, -1}; // Not found
    }

    void solve(int x, int y, int endrow, int endcol, vector<vector<int>>& grid, vector<vector<int>> &vist, int remaining) {
        if (x == endrow && y == endcol) {
            // Check if all non-obstacle cells have been visited
            if (remaining == 0) {
                cnt++;
            }
            return;
        }

        vist[x][y] = 1; // Mark cell as visited

        // Explore all possible directions
        if (issafe(x + 1, y, endrow, endcol, grid, vist)) {
            solve(x + 1, y, endrow, endcol, grid, vist, remaining - 1);
        }
        if (issafe(x, y - 1, endrow, endcol, grid, vist)) {
            solve(x, y - 1, endrow, endcol, grid, vist, remaining - 1);
        }
        if (issafe(x, y + 1, endrow, endcol, grid, vist)) {
            solve(x, y + 1, endrow, endcol, grid, vist, remaining - 1);
        }
        if (issafe(x - 1, y, endrow, endcol, grid, vist)) {
            solve(x - 1, y, endrow, endcol, grid, vist, remaining - 1);
        }

        vist[x][y] = 0; // Unmark cell to allow other paths
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vist(m, vector<int>(n, 0));
        
        auto [startX, startY] = find_start(grid);
        auto [endX, endY] = find_end(grid);

        int totalEmpty = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) totalEmpty++; // Count empty cells
            }
        }
        totalEmpty++; // Include the starting cell

        solve(startX, startY, endX, endY, grid, vist, totalEmpty);

        return cnt;
    }
};