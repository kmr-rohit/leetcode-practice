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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL){
            return res;}
        vector<int> v;
        q.push(root);
        v.push_back(root->val);
        res.push_back(v);
        while(!q.empty()){
            v.clear();
            int size = q.size();
            while(size--){
                 TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                v.push_back(temp->left->val);
            }
            if(temp->right){
                q.push(temp->right);
                v.push_back(temp->right->val);
            }
            
       }
            if(!q.empty()){
           res.push_back(v);
            }
           
  
        }
       
        return res;
        
    }

};