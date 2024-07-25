class Solution{
    public:
    vector<string>ans;
    string temp="";
    
    void f(int i,int j,vector<vector<int>> &m ,
    vector<vector<bool>> &vis, int n){
        
        //base case
        if(i<0 || i>=n || j<0 || j>=n || !m[i][j] || vis[i][j]) return;
        
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        vis[i][j]=1;
        
        //down
        if(i+1<n  && !vis[i+1][j]){
            temp.push_back('D');
            f(i+1,j,m,vis,n);
            temp.pop_back();
        }
        
        //up
         if(i-1>=0  && !vis[i-1][j]){
            temp.push_back('U');
            f(i-1,j,m,vis,n);
            temp.pop_back();
        }
        
        //left
         if(j-1>=0 && !vis[i][j-1]){
            temp.push_back('L');
            f(i,j-1,m,vis,n);
            temp.pop_back();
        }
        
        //right
         if(j+1<n && !vis[i][j+1]){
            temp.push_back('R');
            f(i,j+1,m,vis,n);
            temp.pop_back();
        }
        
        vis[i][j]=false;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        int n = m.size();
        if(!m[0][0]) return ans;
        
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        
        
        f(0,0,m,vis,n);
        return ans;
    }
};