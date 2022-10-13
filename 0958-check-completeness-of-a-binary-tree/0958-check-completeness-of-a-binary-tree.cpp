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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode * > q;
        bool hasNull = false;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for (int i = 0;i<size;i++){
                TreeNode * temp = q.front(); q.pop();
                  if (temp->right && !temp->left) return false;
                
                if (temp->left){
                    if(hasNull) return false; 
                    q.push(temp->left);
                }
                if (temp->right){
                    if(hasNull) return false;
                    q.push(temp->right);
                }
                if ((temp->left && !temp->right )||(!temp->left && !temp->right)){
                    hasNull = true;
                }
            }
        }
        return true;
    }
};