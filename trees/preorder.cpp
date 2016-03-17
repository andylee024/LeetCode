# Leet Code 144 - Binary Tree Preorder Traversal

#include <stack>

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> S;
        vector<int> preorder;
        
        S.push(root);
        while(!S.empty()){
            TreeNode* cur = S.top();
            S.pop();
            
            if(cur->right)
                S.push(cur->right);
            
            if (cur->left) 
                S.push(cur->left);
            
            preorder.push_back(cur->val);
            
        }
        
        return preorder;
    }
};
