class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> arr, int n) 
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
    
     vector<int> prevSmallerElement(vector<int> arr, int n) 
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


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

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
};