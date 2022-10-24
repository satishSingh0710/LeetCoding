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
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) return true;
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode * root, long long int l, long long int h){
        if (!root) return true;
        if (root->val<=l || root->val >=h) return false;
        return  (isValid(root->left, l, root->val)&&isValid(root->right, root->val, h));
    }
};