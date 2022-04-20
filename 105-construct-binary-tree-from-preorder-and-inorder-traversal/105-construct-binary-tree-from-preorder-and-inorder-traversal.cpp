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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int& rootindex , int left ,int right){
        if(left>right){
            return NULL;
        }
        int pivot = left;
        while(inorder[pivot] != preorder[rootindex])pivot++;
        rootindex++;
        
        TreeNode* newnode = new TreeNode(inorder[pivot]);
        newnode->left = construct(preorder , inorder, rootindex , left ,pivot-1);
        newnode->right= construct(preorder ,inorder , rootindex , pivot+1 , right);
        return newnode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootindex = 0;
        return construct(preorder , inorder ,rootindex,0 ,inorder.size()-1);
    
        
    }
};