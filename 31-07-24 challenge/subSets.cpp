class Solution {
public:
   vector<vector<int>>ans;
   vector<int>temp;
    
    bool contains(const vector<vector<int>>& vecOfVecs, const vector<int>& vec) {
    return find(vecOfVecs.begin(), vecOfVecs.end(), vec) != vecOfVecs.end();
    }
    
    void f(int ind, int n, vector<int>&nums){
      if(ind==n){
        if(!contains(ans,temp)){
        ans.push_back(temp);
        }
        return;
      }

      //inclusion wali case
      temp.push_back(nums[ind]);
      f(ind+1,n,nums);
      temp.pop_back();

      //exclusion wali case
      f(ind+1,n,nums);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // ans.clear();
        // temp.clear();

        int n= nums.size();
        sort(nums.begin(),nums.end());
        int ind=0;
        f(ind,n,nums);
        return ans;
    }
};