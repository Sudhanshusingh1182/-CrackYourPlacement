class Solution {
public:
    vector<int> parent;

    // Find the parent 
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    // Union 
    bool Union(int x, int y) {
        int u = findParent(x);
        int v = findParent(y);
        
        
        if (u == v){
          return true; //true matlab pehle se edge hai bhai ..Isse hi htana h 
        }

        parent[u] = v;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        
        vector<int>ans;

        for(int i=0;i<n;i++){
           int u = edges[i][0];
           int v = edges[i][1];
           bool f= Union(u,v);
           
           if(f){
             ans.push_back(u);
             ans.push_back(v);
           }
        }

        return ans;

    }
};