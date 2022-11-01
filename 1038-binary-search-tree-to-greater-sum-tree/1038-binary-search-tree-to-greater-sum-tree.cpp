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
    vector<int> value;
    TreeNode* bstToGst(TreeNode* root) {
        values(root);
        int n = value.size()-1;
        // for (auto &i: value){
        //     cout<<i<<" ";
        // }
        solve(root, n);
        return root;
    }
    
    void solve(TreeNode * root, int &size){
        if (!root) return;
        int i = size, sum = 0;
        while(i>=0 && value[i]>=root->val){
            sum+= value[i]; i--;
        }
        root->val = sum;
        solve(root->left, size); 
        solve(root->right, size);
    }
    void values(TreeNode * root){
        if (!root) return;
        values(root->left); 
        value.push_back(root->val);
        values(root->right);
    }
};