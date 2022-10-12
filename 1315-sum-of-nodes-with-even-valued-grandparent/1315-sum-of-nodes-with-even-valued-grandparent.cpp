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
    private:
    int sum = 0;
    void traversal(TreeNode * root){
        if (!root) return;
        if (root->val % 2 == 0){
            if (root->left){calculate(root->left);}
            if (root->right){calculate(root->right);}
        }
        
        traversal(root->left); traversal(root->right);
    }
    
    void calculate(TreeNode * root){
        if (!root->left && !root->right) return;
        else if (!root->left){sum+= root->right->val; }
        else if (!root->right){sum+= root->left->val;}
        else {
            sum+= root->left->val + root->right->val; 
        }
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        traversal(root);
        return sum;
    }
};