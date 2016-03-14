class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if (!root) return {};
        if (!root->left && !root->right) return {std::to_string(root->val)};
        
        // get subtree paths
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        left.insert( left.end(), right.begin(), right.end());
        
        // append root to each path
        for (auto &p: left){p = std::to_string(root->val) + "->" + p;}
        return left;
        
    }
};
