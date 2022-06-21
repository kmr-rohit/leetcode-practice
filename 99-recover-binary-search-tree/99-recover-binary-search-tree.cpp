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
  vector<int> res;
  int i = 0;
    void inorder(TreeNode* root){
      if(root != NULL){
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
      }
      else{
        return;
      }
    }
  void check(TreeNode* root){
        if(!root) return;
        check(root->left);
        if(res[i]!=root->val) swap(res[i],root->val);
        i++;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
      inorder(root);
      sort(res.begin(), res.end());
      check(root);
      
    }
};