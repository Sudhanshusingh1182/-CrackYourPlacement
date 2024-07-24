class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = nums[0];
        int n= nums.size();
        for(int i=1;i<n;i++){
           if(i<= max_jump) max_jump = max(max_jump , i+ nums[i]);

           else return false;
        }

        return max_jump >=n-1;
    }
};