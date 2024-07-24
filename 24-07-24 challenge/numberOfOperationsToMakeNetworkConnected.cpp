class Solution {
private:
    vector<int>parent;
    vector<int>rank;

    int findParent(int num){
      if(num==parent[num]) return num;

      return parent[num]= findParent(parent[num]);
    }

    void Union(int a , int b){
       
       int parent_a = findParent(a);
       int parent_b= findParent(b);

       if(parent_a == parent_b) return;

       if(rank[parent_a] < rank[parent_b]){
          parent[parent_a]= parent_b;
       }

       else if(rank[parent_a] > rank[parent_b]) parent[parent_b]= parent_a;

       else{
         parent[parent_b]= parent_a;
         rank[parent_a]++;
       }

    }
  
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1) return -1;
        
        parent.resize(n);
        rank.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;

        int components =n;

        for(auto it : connections){
           int num1 = it[0];
           int num2= it[1];

           int par1= findParent(num1);
           int par2= findParent(num2);

           if(par1!=par2) {
              Union(num1 ,num2);
              components--;
           }

           
        }

        return components-1;
    }
};