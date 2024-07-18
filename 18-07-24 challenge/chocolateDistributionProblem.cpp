class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
      
      long long int mini=INT_MAX;
    
    sort(a.begin(),a.end());
    
    for(int i=0;i<=(n-m);i++){
        mini=min(mini,a[i+m-1]-a[i]);
    }
    return mini;
    
    }   
};