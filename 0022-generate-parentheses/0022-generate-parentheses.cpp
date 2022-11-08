
class Solution {
private: 
    vector<string> result;
public:
    void solve(int open, int close, string &temp){
        if (open == 0 && close == 0){
            result.push_back(temp);
            return;
        }
        if (open>0){
            temp+= '(';
            solve(open-1, close, temp);
            temp.pop_back();
        }
        
        if (close>0 && close>open){
            temp+= ')';
            solve(open, close-1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        string temp = "";
        solve(open, close, temp);
        return result;
    }
};