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
    string tree2str( TreeNode* root) {
        string ans;
        tree2Str(root, ans);
        return ans;
    }
    void tree2Str( TreeNode* node, string& ans) {
        if (!node) return;   
        ans += to_string(node->val);
        if (node->left) { //left side check
            ans += '(';
            tree2Str(node->left, ans);
            ans += ')';
        }
        if (node->right) { //right side check
            if (!node->left) ans += "()"; //left side not present, but right side present
            ans += '(';
            tree2Str(node->right, ans);
            ans += ')';
        }
    }
};