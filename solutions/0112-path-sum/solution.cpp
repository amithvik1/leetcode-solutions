/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            return root->val == target;
        }
        int sum = target - root->val;
        return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
    }
};

