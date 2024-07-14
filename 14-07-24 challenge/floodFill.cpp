class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        vector<vector<int>>ans= image;
        int initialColor= image[sr][sc];

        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
              int newr= r+ dr[i];
              int newc= c+ dc[i];

              if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==initialColor && !vis[newr][newc]){
                 vis[newr][newc]=1;
                 ans[newr][newc]=color;
                 q.push({newr,newc});
              }

            } 
        }

        return ans;
        
    }
};