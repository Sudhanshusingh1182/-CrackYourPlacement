class Solution{
private:
bool f(int sum , int arr[] , int ind , vector<vector<int>>&dp){
    
    if(sum==0)  return true;
    
    if(ind==0)  return arr[ind]==sum;
    
    if(dp[ind][sum]!=-1)  return dp[ind][sum];
    
    bool notTake = f(sum , arr,ind-1,dp);
    
    bool take =0;
    if(sum>=arr[ind])
    take = f(sum-arr[ind] , arr , ind-1,dp);
    
    return dp[ind][sum]= take || notTake;
    
}
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        if(sum%2==1)  return 0;
        
        sum = sum/2;
        
        vector<vector<int>>dp(N , vector<int>(sum+1,-1));
        
        return f(sum ,arr,N-1,dp);
        
    }
};