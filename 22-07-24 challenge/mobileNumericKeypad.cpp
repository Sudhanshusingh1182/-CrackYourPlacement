class Solution {
  private:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    long long dp[25][4][3];
    
    long long f(int num, int i, int j){
        //i is the key to be started with
        
        if(num==1) return 1;
        
        if(dp[num][i][j]!=-1) return dp[num][i][j];
        
        long ans=0;
        
        ans+=f(num-1,i,j);
        
        for(int d=0;d<4;d++){
            int newr= i + dr[d];
            int newc= j + dc[d];
            
            if(newr>=0 && newr<4 && newc >=0 && newc <3 && !(newr == 3 && newc == 0) && !(newr == 3 && newc == 2)){
                ans += f(num-1,newr,newc);
            }
        }
        
        return dp[num][i][j]= ans;
    }
  public:
    long long getCount(int n) {
        // Your code goes here
        long long ans= 0;
        
        memset(dp,-1,sizeof(dp));
        
         for(int i=0;i<4;i++){
             for(int j=0;j<3;j++){
                 if(!(i == 3 && j == 0) && !(i == 3 && j == 2)){
                     ans += f(n,i,j);
                 }
             }
         }
        
        return ans;
    }
};