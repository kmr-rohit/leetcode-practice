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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int size = q.size();
            double tempAvg = 0.00000;
            double sum = 0.00000;
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum = sum + (double)temp->val;
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            cout<<sum<<endl;
            tempAvg = sum / size;
            ans.push_back(tempAvg);
            
            
            
        }
        
        return ans;
        
        
    }
};