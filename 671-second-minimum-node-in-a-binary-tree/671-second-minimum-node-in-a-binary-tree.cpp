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
    set<int> s;
    int findSecondMinimumValue(TreeNode* root) {
        find(root);
        int count = 0;
        for (auto &i: s){
            if (count == 1) return i;
            count++;
        }
        return -1;
    }
    void find(TreeNode * root){
        if (!root) return;
        s.insert(root->val);
        find(root->left);
        find(root->right);
    }
};