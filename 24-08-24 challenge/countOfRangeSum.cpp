class Solution {
public:
    long long int merge(int left, int mid, int right, int val, vector<long long int> &v){
        int first = mid-left+1;
        int second = right-mid;
        vector<long long int> a(first+1),b(second+1);
        a[first] = 1e18;
        b[second] = 1e18;
        for(int i=0;i<first;i++){
            a[i]=v[i+left];
        }
        for(int i=0;i<second;i++){
            b[i]=v[i+mid+1];
        }
        long long int ans = 0;
        int i=0,j=0;
        while(i<=first && j<=second){
            if(a[i]>=b[j]-val){
                ans += (first-i);
                j++;
            }
            else{
                i++;
            }
        }
        i=0,j=0;
        for(int x=left;x<=right;x++){
            if(a[i]>b[j]){
                v[x]=b[j];
                j++;
            }
            else{
                v[x]=a[i];
                i++;
            }
        }
        return ans;
    }
    long long int mergeSort(int i, int j, int val, vector<long long int> &v){
        if(i>=j) return 0;
        long long int ans = 0;
        int mid = (i+j)/2;
        ans += mergeSort(i, mid, val, v);
        ans += mergeSort(mid+1, j, val, v);
        ans += merge(i, mid, j, val, v);
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long int> v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i]=nums[i-1];
            v[i] += v[i-1];
        }
        long long int x = mergeSort(0,n,upper,v);
        v[0]=0;
        for(int i=1;i<=n;i++){
            v[i]=nums[i-1];
            v[i] += v[i-1];
        }
        long long int y = mergeSort(0,n,lower-1,v);
        return x-y;
    }
};