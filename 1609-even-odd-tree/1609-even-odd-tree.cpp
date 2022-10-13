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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); int level = 1;
        while(!q.empty()){
            int size = q.size();
            int prev;
            if (level%2==0) prev = INT_MAX;
            else prev = INT_MIN;
            for (int i = 0;i<size;i++){
                TreeNode * temp = q.front(); q.pop();
                if ((level%2==0 && temp->val%2!=0) || (level%2==0 && temp->val>=prev)) return false;
                if ((level%2==1 && temp->val%2==0) || (level%2==1 && temp->val<=prev)) return false;
                if (temp->left)q.push(temp->left);
                if (temp->right)q.push(temp->right);
                prev = temp->val;
            } level++;
        } 
        return true;
    }
};