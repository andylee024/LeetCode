// LeetCode 108 - Convert Sorted Array to Binary Search Tree
// Solution Idea: split down the middle and call function recursively

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if (nums.size() == 0)
            return nullptr;
            
        if (nums.size() == 1){
            TreeNode* t = new TreeNode(nums[0]);
            return t;
        }
        
        if (nums.size() == 2){
            TreeNode* t0 = new TreeNode(nums[0]);
            TreeNode* t1 = new TreeNode(nums[1]); 
            t0->right = t1;
            return t0;
        }
        
        // first split the vector into 2 parts
        std::size_t const half_size = nums.size() / 2;
        std::vector<int> v0(nums.begin(), nums.begin() + half_size);
        std::vector<int> v1(nums.begin() + half_size+1, nums.end());
        TreeNode* root = new TreeNode(nums[half_size]);
        TreeNode* t0 = sortedArrayToBST(v0);
        TreeNode* t1 = sortedArrayToBST(v1);
        root->left = t0;
        root->right = t1;
        return root;
        
    }
};
