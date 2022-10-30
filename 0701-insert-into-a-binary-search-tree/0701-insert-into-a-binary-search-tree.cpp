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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * newNode = new TreeNode(val);
        TreeNode * dummy = root;
        if (!root) return newNode;
        while(root){
            if (val<root->val){
                if (root->left == NULL){
                    root->left = newNode; break;
                } else{
                    root= root->left;
                }
            }else{
                if (root->right == NULL) {
                    root->right = newNode; break;
                }else{
                    root = root->right;
                }
            }
        }
        
        return dummy;
    }
};