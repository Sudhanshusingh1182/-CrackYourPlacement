class Solution {
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        int dp[n][m];
        for(int i=0;i<m;i++) dp[0][i]=(arr[0][i]=='1' ? 1 : 0);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1') dp[i][j]=1+dp[i-1][j];
                else dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            stack<int>from_left,from_right;
            int left[m],right[m];
            for(int j=0;j<m;j++){
                while(!from_left.empty() && dp[i][from_left.top()]>=dp[i][j]){
                    from_left.pop();
                }
                if(from_left.empty()) left[j]=-1;
                else left[j]=from_left.top();
                from_left.push(j);
            }
            for(int j=m-1;j>=0;j--){
                while(!from_right.empty() && dp[i][from_right.top()]>=dp[i][j]){
                    from_right.pop();
                }
                if(from_right.empty()) right[j]=-1;
                else right[j]=from_right.top();
                from_right.push(j);
            }
            int x=0,y=0;
            for(int j=0;j<m;j++){
                if(dp[i][j]==0) continue;
                if(left[j]==-1) x=j+1;
                else x=j-left[j];
                if(right[j]==-1) y=m-j;
                else y=right[j]-j;
                int area=(x+y-1)*dp[i][j];
                ans=max(ans,area);
            }
        }
        return ans;
    }
};