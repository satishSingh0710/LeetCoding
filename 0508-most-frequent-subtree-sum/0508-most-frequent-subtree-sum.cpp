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
    vector<int> res;
    unordered_map<int,int> mp;
    int maxCount = INT_MIN;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        rootOfSubtree(root);
        for (auto &i: mp){
            if (i.second == maxCount){
                res.push_back(i.first);
            }
        }
        return res;
    }
    
    void rootOfSubtree(TreeNode * root){
        if (!root) return;
        int sum = 0;
        findSum(root,sum);
        maxCount = max(maxCount, ++mp[sum]);
        rootOfSubtree(root->left); rootOfSubtree(root->right);
        
     }
    
    void findSum(TreeNode * root, int &sum){
        if (!root) return;
        sum += root->val;
        findSum(root->left, sum); findSum(root->right,sum);
    }
};