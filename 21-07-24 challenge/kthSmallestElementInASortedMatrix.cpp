class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int m= matrix[0].size();
        priority_queue<int>pq; //max heap rkhe h

        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            pq.push(matrix[i][j]);
          }
        }

        while(pq.size()>k) pq.pop();

        return pq.top();
    }
};