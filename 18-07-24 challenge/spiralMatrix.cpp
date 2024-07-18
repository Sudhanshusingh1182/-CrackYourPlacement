class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m= matrix.size();
        int n= matrix[0].size();

        int total= n*m;

        int cnt=0;
        int sr=0;
        int er=m-1;
        int sc=0;
        int ec=n-1; 

        vector<int>ans;

        while(cnt<total){
          //print the first row 

           for(int j=sc;cnt<total && j<=ec; j++){
            ans.push_back(matrix[sr][j]);
            cnt++;
           }
           sr++;

           //printing the ending column
           for(int i=sr; cnt<total && i<=er ;i++){
             ans.push_back(matrix[i][ec]);
             cnt++;
           }
           ec--;

           //printing the last row backwards
           for(int i= ec;cnt<total && i>=sc ; i--){
            ans.push_back(matrix[er][i]);
            cnt++;
           }
           er--;

           //printing the first column backwards
           for(int i= er;cnt<total && i>=sr; i--){
            ans.push_back(matrix[i][sc]);
            cnt++;
           }
           sc++;
        }

        return ans;
    }
};