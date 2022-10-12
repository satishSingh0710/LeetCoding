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
    unordered_map<int,int> mp;
    int deepest = 0;
    int deepestLeavesSum(TreeNode* root) {
        solve(root,0);
        return mp[deepest];
    }
    
    void solve(TreeNode * root, int level){
        if (!root) return;
        deepest = max(level,deepest);
        mp[level] += root->val;
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
};