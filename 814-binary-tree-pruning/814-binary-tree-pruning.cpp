 class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL; 
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return  (root->val == 1 or root->left or root->right) ? root : NULL;
    }
};