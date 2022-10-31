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
    void recoverTree(TreeNode* root) {
        vector<int> nodeVals;
        inOrder(root, nodeVals);
        sort(nodeVals.begin(), nodeVals.end());
        int index = 0;
        recover(root, nodeVals, index);
    }
    
    void recover(TreeNode * root, vector<int> &nodeVals, int &index)
    {
        if (root){
            recover(root->left, nodeVals, index);
            root->val = nodeVals[index];
            index+=1;
            recover(root->right, nodeVals, index);
        }
    }
    void inOrder(TreeNode * root, vector<int> &nodeVals){
        if (root){
            inOrder(root->left, nodeVals);
            nodeVals.push_back(root->val);
            inOrder(root->right, nodeVals);
        }
    }
};