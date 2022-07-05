/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // We will get the balanced tree when root is the middle element
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        else if(nums.size() == 1){
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        
        int middle = nums.size()/2;
        
        vector<int> leftints(nums.begin() , nums.begin() + middle);
        vector<int> rightints(nums.begin() + middle +1 , nums.end());
        
        TreeNode * root = new TreeNode(nums[middle]);
        root->left = sortedArrayToBST(leftints);
        root->right = sortedArrayToBST(rightints);
        
        return root;
    }
};