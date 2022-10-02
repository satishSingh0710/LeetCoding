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
    int res = 0;
    int maxLevel = INT_MIN;
    int findBottomLeftValue(TreeNode* root) {
       solve(root,0);  
        return res;
    }
    
    void solve(TreeNode * root, int level){
        if (!root) return;
        if (level>maxLevel){  maxLevel = level; res = root->val;}
        solve(root->left,level+1); 
        solve(root->right,level+1);
    }
};