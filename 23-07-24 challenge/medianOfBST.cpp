void inorder(Node* root , vector<float>&ans){
    if(!root) return;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

float findMedian(struct Node *root)
{
      vector<float> ans;
      
      inorder(root,ans);
      
      int n= ans.size();
      
      if(n & 1){
          return ans[(n-1)/2];
      }
      
      else return (ans[(n-2)/2]+ ans[n/2])/2; 
}
