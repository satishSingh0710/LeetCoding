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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()){
            bool fX = false, fY = false;
            int size = q.size();
            for (int i = 0;i<size;i++){
                TreeNode *temp = q.front(); q.pop();
                if (temp->left){
                    q.push(temp->left);
                    if (temp->left->val ==x) fX = true;
                    if (temp->left->val == y) fY = true;
                }
                if(temp->right){
                    q.push(temp->right);
                    if (temp->right->val == y) fY = true;
                    if (temp->right->val == x) fX = true;
                }
                
            if (temp->left && temp->right){
                  if((temp->left->val == x && temp->right->val == y) || (temp->left->val == y && temp->right->val == x)) return false;
                 }
             }
            
         if (fX && fY) return true;
            if (fX) return false;
            if (fY) return false;
 }
        
        return true;
    }
};