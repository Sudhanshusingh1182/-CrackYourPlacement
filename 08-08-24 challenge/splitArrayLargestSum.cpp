class Solution {
public:
    bool isPossible(vector<int>arr, int n, int m , int mid){
        int cnt=0;
        int ans=1;
        
        for(int i=0;i<n;i++){
            
            if(cnt + arr[i]<=mid) cnt+=arr[i];
            
            else{
                ans++;
                
                if(ans>m || arr[i]>mid){
                    return false;
                }
                
                cnt= arr[i];
            }
        }
        
        return true;
    }
    

    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        if(k>n) return -1;

        int s=0;
        int e= accumulate(nums.begin(),nums.end(),0);

        int mid= s + (e-s)/2;
        int ans=-1;

        while(s<=e){
          if(isPossible(nums,n,k,mid)){
            ans=mid;
            e=mid-1;
          }

          else s= mid+1;

          mid=s+(e-s)/2;
        }

        return ans;
    }
};