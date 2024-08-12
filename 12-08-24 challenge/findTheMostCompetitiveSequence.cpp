class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int to_pop = n - k; // Number of elements we can pop

        for (int i = 0; i < n; i++) {
            // While the answer is not empty, and we can pop more elements,
            // and the current element is smaller than the last element in the answer
            while (!ans.empty() && to_pop > 0 && ans.back() > nums[i]) {
                ans.pop_back();
                to_pop--;
            }

            // If there's still room in the answer, add the current element
            if (ans.size() < k) {
                ans.push_back(nums[i]);
            } else {
                to_pop--; // No room in the answer, so we're effectively skipping this element
            }
        }

        return ans;
    }
};
