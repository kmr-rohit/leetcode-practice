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
    int minCameraCover(TreeNode* root, bool hasCamera = false, bool isMonitored = false) {
  if (root == nullptr) return 0;
  if (hasCamera) return 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
  if (isMonitored) {
    auto noCam = minCameraCover(root->left, false, false) + minCameraCover(root->right, false, false);
    auto rootCam = 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
    return min(noCam, rootCam);
  }

  if (root->val != 0) return root->val;
  auto rootCam = 1 + minCameraCover(root->left, false, true) + minCameraCover(root->right, false, true);
  auto leftCam = root->left == nullptr ? INT_MAX : minCameraCover(root->left, true, false)
    + minCameraCover(root->right, false, false);
  auto rightCam = root->right == nullptr ? INT_MAX : minCameraCover(root->left, false, false)
    + minCameraCover(root->right, true, false);

  return root->val = min({ rootCam, leftCam, rightCam });
}
};