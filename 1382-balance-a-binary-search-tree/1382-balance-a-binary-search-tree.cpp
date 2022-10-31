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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodeVals;
        inOrder(root, nodeVals);
        return balance(root,nodeVals, 0, nodeVals.size()-1);
    }
    
    TreeNode * balance (TreeNode * root, vector<int> &nodeVals, int l, int h){
        if (l>h) return NULL;
        int mid = (l+h)/2;
        TreeNode * temp = new TreeNode(nodeVals[mid]);
        temp->left = balance(temp, nodeVals, l, mid-1);
        temp->right = balance (temp, nodeVals, mid+1, h);
        return temp;
    }
    
    void inOrder(TreeNode * root, vector<int> &nodeVals){
        if (root){
            inOrder(root->left, nodeVals);
            nodeVals.push_back(root->val);
            inOrder(root->right, nodeVals);
        }
    }
};