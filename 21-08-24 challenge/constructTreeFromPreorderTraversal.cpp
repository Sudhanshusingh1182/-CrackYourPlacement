int curr=0;

Node* solve(int pre[],char preLN[],int n){
    
    if(curr>=n) return NULL;
    Node* root= new Node(pre[curr]);
    
    if(preLN[curr]=='N'){
        curr++;
        root->left = solve(pre,preLN,n);
        curr++;
        root->right= solve(pre,preLN,n);
    }
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{   
    curr=0;
    return solve(pre,preLN,n);
     
}