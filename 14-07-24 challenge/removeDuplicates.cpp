class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>st;

        // for(auto it:nums) st.insert(it);

        int i=1,j=1;
        while(i<nums.size()){
          if(nums[i]!=nums[i-1]){
            nums[j]=nums[i];
            j++;
          }

          i++;
        }

       return j;   
    }
};