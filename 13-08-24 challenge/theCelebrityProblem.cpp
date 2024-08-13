class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n= mat.size();
        //2 elements hmare pass h -> if mat[i][j]==1 -> i knows j , j is potentital candidate to become celeb
        //stack rkh lenge ..Usme potential candidates mil jayenge 
        stack<int>st;
        for(int i=0;i<n;i++) st.push(i);
        
        while(st.size()>1){
            int num1 = st.top(); st.pop();
            
            int num2 = st.top(); st.pop();
            
            if(mat[num1][num2]){ // num1 knows num2 -> num2 ka chance h celeb bnne ka
                st.push(num2);
            }
            
            else st.push(num1);
        }
        
        int res= st.top();
        bool rows= false;
        
        //rowcheck krenge -> no of zeros ==n
        int zeros=0;
        for(int i=0;i<n;i++){
            if(!mat[res][i]) zeros++;
        }
        
        if(zeros==n) rows= true;
        bool cols= false;
        //column check krenge  -> no of 1s == n-1 
        int ones=0;
        for(int i=0;i<n;i++){
            if(mat[i][res]) ones++;
        }
        
        if(ones==n-1) cols = true;
        
        //if rowcheck and columncheck are both true simultaneoulsy , tb return index else return -1
        if(rows && cols) return res;
        
        return -1;
    }
};