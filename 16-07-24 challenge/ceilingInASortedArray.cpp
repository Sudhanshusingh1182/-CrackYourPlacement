
int ceilingValue(vector<int>&arr,int n, int x){
    //array is sorted
    auto it= lower_bound(arr.begin(),arr.end(),x);
    
    int index= it- arr.begin();
    if(index==n) return -1;

    return arr[index];
}