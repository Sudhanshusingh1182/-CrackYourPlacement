class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> PrGr(n);
        PrGr[0] = -1;
        for (int i = 1; i < n; i++) {
            PrGr[i] = max(PrGr[i - 1], nums[i - 1]);
        }
        vector<int> NeGr(n);
        NeGr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            NeGr[i] = max(NeGr[i + 1], nums[i + 1]);
        }

        vector<int> Final(n);
        for (int i = 0; i < n; i++) {
            Final[i] = min(NeGr[i], PrGr[i]);
        }
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] < Final[i]) {
                water += (Final[i] - nums[i]);
            }
        }
        return water;
    }
};