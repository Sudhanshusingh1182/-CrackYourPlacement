class Solution {
public:

 bool isPossible(int n, int k, vector<int> &stalls,int mid){
     
     int lastPos=stalls[0];
     int cowCount=1;
     
     for(int i=0;i<n;i++){
         if(stalls[i]-lastPos >= mid){
            cowCount++;
         
         if(cowCount==k){
             return true;
         }
         lastPos=stalls[i];
         
         }
     }
     return false;
 }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int s=0;
        
        int e=stalls[n-1];
        
        int ans=-1;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if(isPossible(n,k,stalls,mid)){
                ans=mid;
                s=mid+1;
                
            }
            else
            e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};