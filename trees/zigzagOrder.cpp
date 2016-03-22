// Leet Code 103 
// Binary Tree Zigzag Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack> 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        int mark = 0;
        vector<vector<int>> zigzag;
        stack<TreeNode*> S1;
        stack<TreeNode*> S2;
        S1.push(root);
        
        while (!S1.empty() || !S2.empty()){
            vector<int> v;
            
            if (mark == 0){
                while (!S1.empty()){
                    TreeNode* cur = S1.top();
                    if (cur->left)
                        S2.push(cur->left);
                    if (cur->right)
                        S2.push(cur->right);
                    v.push_back(cur->val);
                    S1.pop();
                }
                zigzag.push_back(v);
                mark = 1;
            }
            
            else{
                while (!S2.empty()){
                    TreeNode* cur = S2.top();
                    if (cur->right)
                        S1.push(cur->right);
                    if (cur->left)
                        S1.push(cur->left);
                    v.push_back(cur->val);
                    S2.pop();
                }
                zigzag.push_back(v);
                mark = 0;
            }
        }
        return zigzag;
        
    }
};
