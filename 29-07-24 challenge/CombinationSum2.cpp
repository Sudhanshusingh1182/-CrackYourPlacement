class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;

    bool contains(const vector<vector<int>>& vecOfVecs, const vector<int>& vec) {
    return find(vecOfVecs.begin(), vecOfVecs.end(), vec) != vecOfVecs.end();
    }

    void f(int ind , int n, vector<int>& nums,int target){
      if(target==0 && !contains(ans,temp)){
        ans.push_back(temp);
        return;
      }

      if(target<0 || ind==n) return;

      //inclusion wala case
      if(nums[ind]<=target){
      temp.push_back(nums[ind]);
      f(ind+1,n,nums,target-nums[ind]);
      temp.pop_back();
      }
      int start=ind;
      ind++;
      while(ind<n && nums[ind]==nums[start]) ind++;

      //exclusion wala case
      f(ind,n,nums,target);
    }  
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
         f(0,n,candidates,target);
         return ans;
    }
};