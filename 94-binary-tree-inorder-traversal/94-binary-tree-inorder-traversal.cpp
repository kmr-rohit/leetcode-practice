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
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return v;
        }
        else{
            stack<TreeNode*> s;
            TreeNode* curr = root;
            while(s.empty() == false || curr!= NULL){
                if(curr != NULL){
                    s.push(curr);
                    curr = curr->left;
                }
                
                else{
                    TreeNode* temp = s.top();;
                    s.pop();
                    curr = temp;
                    v.push_back(temp->val);
                    curr = curr->right;
                }
            }
        }
        return v;
    }
};