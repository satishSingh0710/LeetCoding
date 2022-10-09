/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if (!root) return res;
        solve(root); 
        res.push_back(root->val);
        return res;
    }
    
    void solve(Node * root){
        if (!root) return;
        for (int i = 0;i<root->children.size();i++){
            solve(root->children[i]);
            res.push_back(root->children[i]->val);
        }
    }
};