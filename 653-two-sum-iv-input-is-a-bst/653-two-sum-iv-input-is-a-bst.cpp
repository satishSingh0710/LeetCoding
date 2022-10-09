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
    vector<int> temp;
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
       
        for (int i = 0;i<temp.size()-1;i++){
            for (int j = i+1;j<temp.size();j++){
                if (temp[i]+temp[j] == k)return true;
            }
        }
        return false;
    }
    
    void traverse(TreeNode * root){
        if (!root) return;
        temp.push_back(root->val);
        traverse(root->left); traverse(root->right);
    }
    
    
};