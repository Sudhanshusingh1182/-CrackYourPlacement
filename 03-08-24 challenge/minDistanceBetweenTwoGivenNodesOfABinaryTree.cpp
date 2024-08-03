class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
     Node* lowestCommonAncestor(Node* root, Node* a, Node* b) {
        if (!root || root == a || root == b) return root;
        
        Node* left = lowestCommonAncestor(root->left, a, b);
        Node* right = lowestCommonAncestor(root->right, a, b);
        
        if (!left) return right;
        if (!right) return left;
        return root;
    }
    
    // Function to find the distance from a given node to the target node
    int findDist(Node* root, Node* target) {
        if (!root) return INT_MAX;
        if (root == target) return 0;
        
        int leftDist = findDist(root->left, target);
        int rightDist = findDist(root->right, target);
        
        if (leftDist == INT_MAX && rightDist == INT_MAX) return INT_MAX;
        return 1 + min(leftDist, rightDist);
    }
    
    // Function to find the distance between nodes with values a and b
    int findDist(Node* root, int a, int b) {
        Node* nodeA = findNode(root, a);
        Node* nodeB = findNode(root, b);
        
        if (!nodeA || !nodeB) return -1; // If either node is not found
        
        Node* lca = lowestCommonAncestor(root, nodeA, nodeB);
        
        if (!lca) return -1; // LCA should not be null if nodes are present
        
        int distA = findDist(lca, nodeA);
        int distB = findDist(lca, nodeB);
        
        if (distA == INT_MAX || distB == INT_MAX) return -1; // If any distance is invalid
        
        return distA + distB;
    }
    
private:
    // Helper function to find a node with a given value
    Node* findNode(Node* root, int value) {
        if (!root) return nullptr;
        if (root->data == value) return root;
        
        Node* left = findNode(root->left, value);
        if (left) return left;
        
        return findNode(root->right, value);
    }
};    