class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n= nums2.size();
        vector<int>temp(n);

        stack<int>st;
        temp[n-1]=-1;
        st.push(nums2[n-1]);

        int i=n-2;
        while(i>=0){
           
           if(!st.empty() && nums2[i] <st.top()){
            temp[i]= st.top();
           }

           else{
             while(!st.empty() && nums2[i]> st.top()){
               st.pop();
             }

             if(st.empty()) temp[i]=-1;

             else temp[i]=st.top();
           }
           st.push(nums2[i]);
           i--;
        }

        map<int,int>mp;

        for(int i=0;i<n;i++){
          mp[nums2[i]]= temp[i];
        }

        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
           auto it = mp.find(nums1[i]);
           ans[i]=it->second;
        }

        return ans;


    }
};