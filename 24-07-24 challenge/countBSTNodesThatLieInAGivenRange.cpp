class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
       
       if(!root) return 0;
       
       int ans=0;
       
       if(root->data >= l && root->data <=h)  ans+=1;
       
       ans+= getCount(root->left,l,h);
       ans+=getCount(root->right,l,h);
       
       return ans;
    }
};