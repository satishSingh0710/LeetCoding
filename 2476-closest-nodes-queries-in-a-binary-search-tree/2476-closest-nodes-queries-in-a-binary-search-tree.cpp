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
    void solve(TreeNode * root){
        if (root){
            temp.push_back(root->val);
            solve(root->left);
            solve(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        solve(root);
        sort(temp.begin(), temp.end());
        vector<vector<int>> fRes;
        for (auto &i: queries){
            vector<int> res;
            
            
            auto iter = std::lower_bound(temp.rbegin(), temp.rend(), i, std::greater<int>());
if(iter == temp.rend())
    res.push_back(-1);
else
    res.push_back(*iter);
            
            
            auto ite = upper_bound(temp.begin(), temp.end(), i-1);
            if (ite == temp.end()){res.push_back(-1);}
            else{res.push_back(*ite);}
            fRes.push_back(res);
        }
        
        return fRes;
    }
};