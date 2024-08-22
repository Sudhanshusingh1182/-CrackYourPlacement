class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        //convert into 1D array
        vector<int>arr;
        vector<int>vis(n*n+1,0);
        int ind=0;
        
        arr.push_back(0);

        for(int i=n-1;i>=0;i--){
           if(ind%2 ==0){
             for(int j=0;j<n;j++) arr.push_back(board[i][j]);
           }

           else{
            for(int j=n-1;j>=0;j--) arr.push_back(board[i][j]);
           }
           ind++;
        }

        queue<pair<int,int>>q;
        q.push({1,1});
        vis[1]=1;

        while(!q.empty()){
          int sz= q.size();
          for(int i=0;i<sz;i++){
            auto [num,steps]= q.front();
            q.pop();

            if(num==n*n) return steps;

            for(int j=1;j<7;j++){
              int newInd = num + j;

              if(arr[newInd]!=-1) newInd= arr[newInd];
              if(newInd== n*n) return steps;
              
              if(vis[newInd]) continue;
              else{
                vis[newInd]=1;
                q.push({newInd,steps+1});
              }

            }
          }
        }


      return -1;

    }
};