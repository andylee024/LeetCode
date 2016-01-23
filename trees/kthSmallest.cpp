    
/*
LeetCode #230

Solution:

The tree that is given is a Binary Search Tree, which means that an inOrder
traversal will yield the elements in order. Therefore, we run Inorder traversal
and output the kth element of that vector. 

*/

#include <vector>
// recursive solution 
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> V;
        inOrder(root, V);
        return V[k-1];
    }
    
    void inOrder(TreeNode* root, vector<int> &V){
        if (!root){return;}
        if (root->left){inOrder(root->left, V);}
        V.push_back(root->val);
        if (root->right){inOrder(root->right, V);}
}

// iterative solution
#include <stack>
#include <vector>
    
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> V;
        inOrder(root, V,k);
        return V[k-1];
    }
    
    void inOrder(TreeNode* root, vector<int> &V, int k){
        if (!root){return;}
        TreeNode* cur = root;
        stack<TreeNode*> S;
        
        while(!S.empty() || cur){
            if (cur){
                S.push(cur);
                cur = cur->left;
            }
            
            else{
                cur = S.top();
                S.pop();
                V.push_back(cur->val);
                cur = cur->right;
            }
            
            if (V.size() >= k){return;}
        }
    }
}; 
