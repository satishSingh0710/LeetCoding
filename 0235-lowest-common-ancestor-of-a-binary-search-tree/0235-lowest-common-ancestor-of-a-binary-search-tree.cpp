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
        if (!root) return NULL;
        if (root == p || root == q) return root;
        if ((p->val < root->val && q->val > root->val) || (p->val>root->val && q->val < root->val)) return root;
        TreeNode * find;
        if (p->val > root->val && q->val > root->val){
            find = lowestCommonAncestor(root->right, p,q);
        } else{
            find = lowestCommonAncestor(root->left, p,q);
        }
        return find;
        
    }
};