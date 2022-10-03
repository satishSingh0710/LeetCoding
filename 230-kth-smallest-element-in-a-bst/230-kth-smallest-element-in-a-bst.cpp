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
    priority_queue<int, vector<int>, greater<int> > q;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        int ans = -1;
        traversal(root);
        while (k--){
             ans = q.top(); q.pop();
        }
        
        return ans;
    }
    
    void traversal(TreeNode * root){
        if (!root) return ;
        q.push(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    
};