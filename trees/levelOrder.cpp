/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>
using namespace std;

/*
Iterative solution to level order traversal
Leet Code Problem 102
*/

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // initialization
        vector<vector<int> > levelOrder;
        int level = 0;
        queue<TreeNode*> Q;
        
         // null root
        if (!root){return levelOrder;}
        
        // iterative level order 
        Q.push(root);
        while(!Q.empty()){
            vector<int> newLevel;
            levelOrder.push_back(newLevel);
            int levelSize = Q.size();
            
            for (int i=0; i<levelSize; i++){
                TreeNode* cur = Q.front();
                Q.pop();
                levelOrder[level].push_back(cur->val);
                if (cur->left){Q.push(cur->left);}
                if (cur->right){Q.push(cur->right);}
            }
            level++;
        }
        return levelOrder;
    }
};
