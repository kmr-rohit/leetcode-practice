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
    void traversal(TreeNode * root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        
        traversal(root->left , arr);
        arr.push_back(root->val);
        traversal(root->right, arr);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        traversal(root,arr);
        
        return arr[k-1];
    }
};