/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)return NULL;
        int currVal = root->val;
        if (p->val > currVal && q->val > currVal) return lowestCommonAncestor(root->right, p,q);
        if (p->val < currVal && q->val < currVal) return lowestCommonAncestor(root->left, p,q);
        return root;
    }
};