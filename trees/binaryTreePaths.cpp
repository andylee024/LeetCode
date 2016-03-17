// LeetCode Problem 257 

// Direct solution 
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

// DFS solution
class Solution {
public:
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        if (!root) return {};
        if (!root->left && !root->right) return {std::to_string(root->val)};
        dfs(root, "", allPaths);
        return allPaths;
       
    }
    
    void dfs(TreeNode* root, string currentPath, vector<string> &allPaths){
        currentPath += std::to_string(root->val);
        if (!root->left && !root->right) allPaths.push_back(currentPath); // leaf reached, add path
        
        else{
            if(root->left) dfs(root->left, currentPath+"->", allPaths); // continue left subtree
            if(root->right) dfs(root->right, currentPath+"->", allPaths); // continue right subtree
        }
        
    }
};

