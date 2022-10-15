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
    int xDepth = 0, yDepth = 0;
    bool siblings = false;
    bool isCousins(TreeNode* root, int x, int y) {
        findDepth(root,x,y,0);
        return (xDepth == yDepth && !siblings);
    }
    void findDepth(TreeNode * root, int &x, int &y, int depth){
        if (!root || siblings) return;
        if (xDepth!=0 && yDepth != 0) return;
         if (root->right && root->left){
             if ((root->left->val == x)&&(root->right->val==y) || (root->right->val == x && root->left->val == y)) {siblings = true; return;}     
         }
        
        
        if(root->val == x){
            xDepth = depth;
        } else if (root->val == y){
            yDepth = depth;
        }
        
        findDepth(root->left, x,y,depth+1);
        findDepth(root->right, x,y,depth+1);
    }
};