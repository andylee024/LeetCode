// Leet Code 145 - Binary Tree Postorder traversal
// Solution Idea:
// The key to note is that we need a way to mark the status of the node
// 0 - node has not visited any children
// 1 - node has visited left child
// 2 - node has visited right child 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> postorder;
        stack<TreeNode*> S1;
        stack<int> S2;
        
        S1.push(root);
        S2.push(0);
        
        while(!S1.empty()){
            TreeNode* cur = S1.top();
            int curInt = S2.top();
            S2.pop();
            
            if (curInt == 0){
                S2.push(1);
                if (cur->left){
                    S1.push(cur->left);
                    S2.push(0);    
                }
            }
            
            
            if (curInt == 1){
                S2.push(2);
                if (cur->right){
                    S1.push(cur->right);
                    S2.push(0);    
                }
            }
            
            if (curInt == 2){
                S1.pop();
                postorder.push_back(cur->val);
            }
        }
        return postorder;
    }
};
