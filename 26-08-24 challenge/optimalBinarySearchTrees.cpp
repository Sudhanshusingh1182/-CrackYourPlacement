class Solution{
    private:
    int solve(int i, int j, int *keys, int *freq, vector<vector<int>> &dp)
    {
    
        if (i == j)
        {
            return freq[i];
        }
    
        if (i > j)
        {
            return 0;
        }
    
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
    
        // to account for the current node, all the nodes will increase
        // its height by 1 + the current nodes frequency
        int cur = 0;
        for (int k = i; k <= j; k++)
        {
            cur += freq[k];
        }
    
        int ans = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            // if k is the root node
            int left = solve(i, k - 1, keys, freq, dp);
            int right = solve(k + 1, j, keys, freq, dp);
            ans = min(ans, left + right + cur);
        }
        return dp[i][j] = ans;
    }
    
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, keys, freq, dp);
    }
};