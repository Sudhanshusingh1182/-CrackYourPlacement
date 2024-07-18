class NumArray {
public:
    int n;
    vector<int>seg;
    vector<int>input;

    void buildSegmentTree(int i , int l ,int r){
      if(l==r){
        seg[i]= input[l];
        return;
      }

      int mid= l+(r-l)/2;

      buildSegmentTree(2*i+1,l,mid);
      buildSegmentTree(2*i+2, mid+1,r);
      seg[i]= seg[2*i+1]+seg[2*i+2];

    }

    void updateSegmentTree(int ind , int val ,int i, int l , int r){
        if(l==r){
          //we have reached the node to be deleted
          seg[i]= val;
          return;
        }

        int mid= l+(r-l)/2;

        if(ind<=mid){
          updateSegmentTree(ind,val,2*i+1,l,mid);

        }

        else updateSegmentTree(ind,val,2*i+2,mid+1,r);

        seg[i]=seg[2*i+1]+seg[2*i+2];
    }

    int sumSegment(int start, int end , int i , int l ,int r){
       //3 cases are there
       //start end is the query given in the question
        if(l>end || r<start) return 0;

        if(l>=start && r<=end) return seg[i];

        int mid=l+(r-l)/2;

        return sumSegment(start,end,2*i+1, l,mid) + sumSegment(start,end,2*i+2,mid+1,r);

    
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        input=nums;
        seg.resize(4*n,0);
        buildSegmentTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return sumSegment(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */