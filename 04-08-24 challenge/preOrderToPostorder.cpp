class Solution {
  public:
    Node * preToBST(int pre[] , int &i , int size , int mini , int maxi){
       
       if(i>=size)
       return NULL;
       
       int x=pre[i];
       
       if(x<mini || x>maxi)
       return NULL;
       
       Node * root= newNode(x);
       i++;
       
       root->left= preToBST(pre,i,size,mini,x);
       root->right= preToBST(pre,i,size,x,maxi);
       
       return root;
   }

  
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        //code here
        int i=0;
        Node * root= preToBST(pre,i,size,INT_MIN,INT_MAX);
        
        return root;
    }
};