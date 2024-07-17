class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxi=INT_MIN;
        double mul=1;

        for(int i=0;i<nums.size()-1;i++){
          mul*=nums[i];
          maxi=max(maxi,mul);
          if(mul==0) mul=1;
        }
        mul=1;
        for(int i=nums.size()-1;i>=0;i--){
          mul*=nums[i];

          maxi=max(mul,maxi);
          if(mul==0) mul=1;
        }

        return (int)maxi;
    }
};