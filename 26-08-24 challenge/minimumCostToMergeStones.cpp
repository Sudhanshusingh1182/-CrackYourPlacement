class Solution {
public:
    int solve(int low, int high, vector<int>& prefix, int k, vector<vector<int>>& dp) {
        if (low >= high) {
            return 0;
        }
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        int ans = INT_MAX;
        for (int x = low; x < high; x += (k - 1)) {
            int sum = solve(low, x, prefix, k, dp) + solve(x + 1, high, prefix, k, dp);
            ans = min(ans, sum);
        }
        if ((high - low) % (k - 1) == 0) {
            ans += prefix[high + 1] - prefix[low];
        }
        return dp[low][high] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, prefix, k, dp);
    }
};