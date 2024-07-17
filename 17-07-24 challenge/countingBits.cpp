class Solution {
private:
    void solve(int i , vector<int>&ans){

      int cnt=0;
      while(i!=0){
        if(i%2==1)   cnt++;  

        i=i/2;
      }

      ans.push_back(cnt);
    }

public:
    vector<int> countBits(int n) {
        
        // vector<int>ans;

        // for(int i=0;i<=n;i++){
        //   solve(i,ans);
        // }

        // return ans;

        // for(int i=0;i<=n;i++){
        //   int sum=0;
        //   int num=i;

        //   while(num!=0){
        //     sum+=num%2;
        //     num=num/2;
        //   }

        //   ans.push_back(sum);
        // }

        // return ans;

        //solving it using dp

        vector<int>dp(n+1);

        if(n==0)  return dp;

        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
          dp[i]=i%2 + dp[i/2];
        }

        return dp;

    }
};