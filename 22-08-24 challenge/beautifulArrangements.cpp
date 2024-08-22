class Solution {
public:
    int count = 0;

    void solve(int pos, int n, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                solve(pos + 1, n, used);
                used[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        solve(1, n, used);
        return count;
    }
};
