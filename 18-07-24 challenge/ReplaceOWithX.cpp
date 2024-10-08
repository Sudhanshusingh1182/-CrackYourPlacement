class Solution{
private : 
void dfs(int row , int col ,vector<vector<int>>& vis,
vector<vector<char>> &mat ,  int delRow[] , int delCol[]){
    
    vis[row][col]=1;
    
    int n = mat.size();
    int m = mat[0].size();
    
    for(int i=0;i<4;i++){
        
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        
        if(newRow >=0 && newRow <n && newCol >=0 && newCol <m &&
        !vis[newRow][newCol] && mat[newRow][newCol]=='O'){
            
            dfs(newRow , newCol , vis , mat , delRow , delCol);
        }
    }
    
    
}
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // we will use dfs algorithm here
        
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,1,0,-1};
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        //traversing first row and last row 
        
        for(int j=0;j<m;j++){
            
            //first row 
            
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis , mat ,delRow , delCol);
            }
            
            //last row 
            if(!vis[n-1][j] && mat[n-1][j]=='O')
            dfs(n-1,j,vis,mat,delRow,delCol);
        }
        
        //traversing first col and last col 
        
        for(int i=0;i<n;i++){
            
            //first col 
            
            if(!vis[i][0] && mat[i][0]=='O')
             dfs(i,0,vis,mat,delRow,delCol);
             
             //last col
             
             if(!vis[i][m-1] && mat[i][m-1]=='O')
             dfs(i,m-1,vis,mat,delRow,delCol);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(!vis[i][j] && mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        
        return mat;
    }
};