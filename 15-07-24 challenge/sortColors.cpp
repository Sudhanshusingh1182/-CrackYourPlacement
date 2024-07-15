class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int nz=0 ,no=0,nt=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0)  nz++;

        else if(arr[i]==1) no++;

        else  nt++;
    }

    for(int i=0;i<nz;i++)  arr[i]=0;

    for(int i=nz;i<nz+no;i++)  arr[i]=1;

    for(int i=nz+no;i<nz+no+nt;i++)  arr[i]=2;
    }
};