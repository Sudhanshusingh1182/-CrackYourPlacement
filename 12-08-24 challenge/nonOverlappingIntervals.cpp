class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
      return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n= intervals.size();
        sort(begin(intervals),end(intervals),comp);

        int cnt=0;
        int i=0;
        int j=1;
        
        while(i<n && j<n){ 
           if(intervals[i][1] > intervals[j][0]) {
              cnt++;
              j++;
           }

           else{
              i=j;
              j++;
           }
        }

        return cnt;
        
    }
};