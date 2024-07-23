class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>>res; 
        set<vector<int>> st;
        sort(nums.begin(),nums.end());

        if(nums[0] >0 && target >0 && nums[0] > target ) return {};

        int n= nums.size();

        for(int i=0;i<n-3;i++){
          for(int j= i+1;j<n-2;j++){
               
              //  if(j>0 && nums[j]==nums[j-1]) continue;

               int s= j+1 , e= n-1;

               while(s<e){
                  long long int sum= (long long int)nums[i]+ nums[j] + nums[s]+ nums[e];

                  if(sum==target){
                      st.insert({nums[i],nums[j],nums[s],nums[e]});

                      // while(s<e && nums[s]==nums[s+1]) s++;

                      // while(s<e && nums[e]==nums[e-1]) e--;

                      ++s,--e; 
                  }

                  else if(sum< target) ++s;

                  else e--;
               }
          }
        }

        for(auto it:st) res.push_back(it);

        return res;
    }
};