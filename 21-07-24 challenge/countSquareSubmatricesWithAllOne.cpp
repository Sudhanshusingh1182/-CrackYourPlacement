class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        int m= matrix[0].size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(i>0 && j>0 && matrix[i][j]==1){
              matrix[i][j]= min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]}) +1;

            }
            cnt+= matrix[i][j];
          }
        }

        return cnt;
    }
};