class Solution 
{
public:
    vector<int> in;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        inorder(root);
        for(int i=1;i<in.size();i++)
        {
            if(in[i-1]>=in[i])
                return false;
        }
        return true;
    }
};