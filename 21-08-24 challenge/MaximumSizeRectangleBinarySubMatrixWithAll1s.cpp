class Solution{
  public:
    
    vector<int> nextSmallerElement(int *arr, int n) 
    { 
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    } 
    
     vector<int> prevSmallerElement(int *arr, int n) 
    { 
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            
            st.push(i);
        }
        
        return ans;
    } 


    int largestRectangleArea(int * heights, int n) {

        vector<int>prev(n),next(n);
        next = nextSmallerElement(heights,n);
        prev = prevSmallerElement(heights,n);
        int maxArea= INT_MIN;

        for(int i=0;i<n;i++){
          int l = heights[i];
          if(next[i]==-1) next[i]=n;
          int w= next[i]-prev[i]-1;
    
          int area = l*w;
          maxArea= max(maxArea,area);
        }

        return maxArea;

    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //compute area for first row 
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row update 
                if(M[i][j]!=0) M[i][j]+= M[i-1][j];
                
                else M[i][j]=0;
                
            }
            
            area = max(area,largestRectangleArea(M[i],m));
        }
        
        return area;
    }
};