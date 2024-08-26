class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

    
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int start = n - 1; start >= 0; start--) {
            curr[start] = 1;  // Single character is a palindrome of length 1
            for (int end = start + 1; end < n; ++end) {
                if (s[start] == s[end]) {
                    curr[end] = 2 + prev[end - 1];
                } else {
                    curr[end] = max(prev[end], curr[end - 1]);
                }
            }
            prev = curr;  // Move current row to previous for the next iteration
        }

        return n-curr[n - 1];
    }
};