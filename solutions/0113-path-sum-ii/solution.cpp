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
    void dfs(TreeNode* root, int target , vector<int>& curr, vector<vector<int>>& res){
        if(root == nullptr) return; 
        curr.push_back(root->val); 
        target -= root->val; 
        if(root->left == nullptr && root->right == nullptr && target == 0){
            res.push_back(curr); 
        }
        dfs(root->left,target,curr,res); 
        dfs(root->right,target,curr,res); 
        curr.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>res; 
        vector<int> curr; 
        dfs(root, target, curr, res); 
        return res;
    }
};
