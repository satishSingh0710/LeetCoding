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
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        findOut(root);
        return ans;
    }
    
    void findOut(TreeNode * root){
        if (!root) return;
        int lNodes = 0, rNodes = 0;
        int leftSum = 0 ,rightSum =0;
        sum(root->left,lNodes,leftSum);
        sum(root->right,rNodes,rightSum);
        if ((leftSum + rightSum + root->val)/ (lNodes + rNodes + 1) == root->val) ans++;
        
        findOut(root->left); findOut(root->right);
    }
  
    void sum(TreeNode * root, int &count, int &summ){
        if (!root) return;
        
        summ += root->val; count++;
        sum(root->left, count, summ);
        sum(root->right, count, summ);
    }
};