class Solution {
public:
    int mod = 1e9 + 7;

    long fRec(int i, int j, int n, vector<vector<vector<long>>>& dp) {
        if (i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        
        if (n == 1) return 1;

        if (dp[n][i][j] != -1) return dp[n][i][j];
        
        return dp[n][i][j] = (
            fRec(i-1, j-2, n-1, dp) % mod +
            fRec(i-2, j-1, n-1, dp) % mod +
            fRec(i-2, j+1, n-1, dp) % mod +
            fRec(i-1, j+2, n-1, dp) % mod +
            fRec(i+1, j-2, n-1, dp) % mod +
            fRec(i+2, j-1, n-1, dp) % mod +
            fRec(i+1, j+2, n-1, dp) % mod +
            fRec(i+2, j+1, n-1, dp) % mod
        ) % mod;
    }

    int knightDialer(int n) {
        long ans = 0;
        
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(4, vector<long>(3, -1)));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans = (ans + fRec(i, j, n, dp) % mod) % mod;
            }
        }

        return (int) ans;
    }
};
