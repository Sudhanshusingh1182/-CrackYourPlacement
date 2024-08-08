class Solution {
public:
     typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<p>vec;

        for(int i=0;i<points.size();i++){
           int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];

           vec.push_back({dist,{points[i][0],points[i][1]}}); 
        }

        priority_queue<p, vector<p>, greater<p>>pq;

        for(auto it:vec){
          pq.push({it.first,{it.second.first,it.second.second}});
        }

        vector<vector<int>>ans;

        while(k--){
            auto top = pq.top();
            ans.push_back({top.second.first,top.second.second});
            pq.pop();
        }

        return ans;
    }
};