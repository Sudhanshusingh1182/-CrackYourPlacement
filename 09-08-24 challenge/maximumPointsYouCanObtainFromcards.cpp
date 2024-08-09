class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int left_sum=0, right_sum=0;
        int maxSum=0;
        for(int i=0;i<k;i++) left_sum+=cardPoints[i];
        
        maxSum=left_sum;
        
        int rightInd= cardPoints.size()-1;

        for(int i=k-1;i>=0;i--){
          left_sum-=cardPoints[i];
          right_sum+=cardPoints[rightInd];
          rightInd--;
          maxSum= max(maxSum , right_sum+ left_sum);
        }

        return maxSum;
 
    }
};