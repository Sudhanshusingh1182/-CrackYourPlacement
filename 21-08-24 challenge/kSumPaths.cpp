class Solution {
public:
    int sumK(Node* root, int k) {
        if (!root) return 0;   
    
        int fromRoot = pathSumFromNode(root, k);
        
        int leftPaths = sumK(root->left, k);
        int rightPaths = sumK(root->right, k);
        
        return fromRoot + leftPaths + rightPaths;
    }
    
private:
    
    int pathSumFromNode(Node* node, int k) {
        if (!node) return 0;  
    
        int count = (node->data == k) ? 1 : 0;
        
        count += pathSumFromNode(node->left, k - node->data);
        count += pathSumFromNode(node->right, k - node->data);
        
        return count;
    }
};