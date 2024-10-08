typedef unsigned long long ll;
class Solution {
public:
    vector<int>getNsl(vector<int>&arr , int n){
      vector<int>res(n);
      stack<int>st;
      for(int i=0;i<n;i++){
         if(st.empty()){
           res[i]= -1;
         }

         else{
          while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

          res[i]= st.empty() ? -1 : st.top();
         }

         st.push(i);
      }

      return res;
    }

    vector<int>getNsr(vector<int>&arr , int n){
      vector<int>res(n);
      stack<int>st;
      for(int i=n-1;i>=0;i--){
         if(st.empty()){
           res[i]= n;
         }

         else{
          while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

          res[i]= st.empty() ? n : st.top();
         }

         st.push(i);
      }

      return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        ll mod = 1e9 + 7;
        int n = arr.size();
        vector<int>nsl = getNsl(arr,n);
        vector<int>nsr = getNsr(arr,n);
        
        ll ans=0;

        for(int i=0;i<n;i++){
           ll d1= i - nsl[i];
           ll d2= nsr[i] - i;

           ll total = d1*d2;

           ll contri= arr[i]*total;

           ans= (ans + contri)%mod;
        }

        return ans;

    }
};