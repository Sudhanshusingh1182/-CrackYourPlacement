class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
      
        long long int totalProduct = 1;
        int zeroCount = 0;
        
        for (auto it : nums) {
            if (it != 0) {
                totalProduct *= it;
            } else {
                zeroCount++;
            }
        }
        
        
        vector<long long int> ans(n, 0);

        if (zeroCount > 1) {
            
            return ans;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
               
                ans[i] = totalProduct;
            } else if (zeroCount == 0) {
               
                ans[i] = totalProduct / nums[i];
            }
        }
        
        return ans;
    }
};