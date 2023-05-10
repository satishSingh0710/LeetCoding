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
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        vector<vector<int>> fres; 
         if (!root) return fres;
        queue<TreeNode*> q; 
        q.push(root); 
        while(q.size()){
            int size = q.size();
            vector<int> res; 
            for (int i = 0;i<size;i++){
                auto currNode = q.front(); q.pop(); 
                res.push_back(currNode->val); 
                if (currNode->left){q.push(currNode->left);}
                if(currNode->right){q.push(currNode->right);}
            }
            fres.push_back(res);
        }
        return fres; 
    }
};