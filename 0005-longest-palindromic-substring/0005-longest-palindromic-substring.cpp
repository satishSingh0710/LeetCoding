class Solution {
public:
    // int solve(string &s, int l, int r, vector<vector<int>> &dp){
    //     if (l>r) return 0;
    //     if (s[l] == s[r]){
    //         if (l == r) return dp[l][r] = 1;
    //         return dp[l][r] = 2 + solve(s, l+1, r-1,dp);
    //     }
    //     else return  dp[l][r] = max(0 + solve(s, l+1,r,dp), 0 + solve(s, l, r-1,dp));
    // }
    string longestPalindrome(string s) {
        vector<vector<bool>> store(s.size(), vector<bool> (s.size(), false));
        for (int i = 0;i<s.size();i++){
            int row = 0, col = i;
            while(col < s.size() && row < s.size()){
                if(col - row == 0){
                    if (s[col] == s[row]) store[row][col] = true;
                }else if (col - row == 1){
                    if (s[row] == s[col]) store[row][col] = true;
                }else{
                    if (s[row] == s[col]){
                        store[row][col] = store[row+1][col-1];
                    }
                }
                row++; col++;
            }
        }
        string res = "";
        for (int i = 0;i<s.size();i++){
            for (int j = 0;j<s.size();j++){
                if (i>j) continue;
                if (j - i + 1 > res.size() && store[i][j]  == true){
                    res = s.substr(i, j - i +1);
                }
            }
        }
        
        return res;
        
    }
};