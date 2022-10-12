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
    int deepestLeavesSum(TreeNode* root) {
        int depth = findDepth(root), sum = 0;
        findSum(root,1, depth,sum);
        return sum;
    }
    void findSum(TreeNode * root, int level, int &depth, int &sum){
        if (!root) return;
        if (level == depth){sum+= root->val;}
        findSum(root->left, level+1, depth, sum);
        findSum(root->right,level+1, depth,sum);
    }
    int findDepth(TreeNode * root){
        if (!root) return 0;
        int lh = findDepth(root->left);
        int rh = findDepth(root->right);
        return 1+max(lh,rh);
    }
};