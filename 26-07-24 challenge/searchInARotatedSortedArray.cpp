class Solution {
public:
    int pivotPoint(vector<int>arr){
      int x=0;
      for(int i=1;i<arr.size()-1;i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
        x=i;
        break;
        }
      }
      return x;
    }

    int binarySearch(vector<int> nums, int target, int start, int end){

      int s=start;
      int e=end;

      int mid=s+(e-s)/2;
      bool f=0;
      while(s<=e){
        if(nums[mid]==target){
          f=1;
          return mid;
        }
        else if(nums[mid]<target){
          s=mid+1;
        }
        else
        e=mid-1;

        mid=s+(e-s)/2;
      }
      if(f==0)
      return -1;
      else
      return mid;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot=pivotPoint(nums);

        int s=0,e=nums.size()-1;

        if(target>=nums[0] && target<=nums[pivot]){
          return binarySearch(nums,target,0,pivot);
        }
        else
        return binarySearch(nums,target,pivot+1,e);
    }
};