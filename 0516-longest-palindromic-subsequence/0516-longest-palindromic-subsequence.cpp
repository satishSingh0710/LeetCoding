class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if (i>=a.size() || j>=b.size()){
            return 0; 
        }
        if (dp[i][j] != -1) return dp[i][j];
        int same = 0, notSame = 0; 
        if (a[i] == b[j]){
            same = 1 + solve(a, b, i+1, j+1,dp); 
        }else{
            notSame = 0+ max(solve(a,b,i+1, j,dp), solve(a,b,i,j+1,dp));
        }
        return  dp[i][j]= max(same, notSame);
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        string t = s;
        reverse(t.begin(), t.end());
        return solve(s, t, 0,0,dp);
    }
};