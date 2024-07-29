class Solution {
public:
    typedef  pair<pair<int,int>,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

       vector<vector<pair<int,int>>>adj(n);  //node -cost

       for(auto it : flights){                                                  //TC -> o(N) : no of edges ke barabaar
          adj[it[0]].push_back({it[1],it[2]});
       }
       
       priority_queue<p,vector<p>,greater<p>>pq;
       vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
       
       pq.push({{0,src},0});  //cost- node - steps no..                             
       dist[src][0]=0 ; // src with K stops -> 0

       while(!pq.empty()){                                                    //ATMAX Sare nodes ek baar traverse honge -> TC : o(N)
           auto it = pq.top();
           pq.pop();
           int cost = it.first.first;
           int node = it.first.second;
           int steps= it.second;

           if(node==dst) return cost;

           if(steps>k) continue;

           for(auto it: adj[node]){
              int adjNode = it.first;
              int c = it.second;

              if(cost + c <dist[adjNode][steps+1]){
                  dist[adjNode][steps+1]= cost + c;
                  pq.push({{cost + c, adjNode},steps + 1});
              }
           }
       }

        return -1; 

    }
};