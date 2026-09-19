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
    void inorder(TreeNode* root , TreeNode*& prev , int& m){
        if(root == nullptr) return; 
        inorder(root->left, prev, m);
        if(prev != nullptr){
            m = min(m , root->val - prev->val);
        }
        prev = root; 
        inorder(root->right, prev, m);
    }
    int getMinimumDifference(TreeNode* root) {
        int m = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, m);
        return m;
    }
};
