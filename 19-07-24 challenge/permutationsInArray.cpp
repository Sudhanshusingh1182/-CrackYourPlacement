class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        
        long long i=0;
        while(i<n){
            if(a[i]+b[i] <k) return false;
            i++;
        }
        
        return true;
        
    }
};