class Solution {
public:
    int solve(string &s, string &t, int i , int j, vector<vector<int>> &dp){
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i-1] == t[j-1]) return  dp[i][j]  = 1 + solve(s,t, i-1,j-1, dp);
        return dp[i][j] = 0 + max(solve(s,t,i-1,j,dp), solve(s,t,i,j-1,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        solve(str1,str2, n,m,dp);
        string res = "";
        while(n>0 && m>0){
            if (str1[n-1] == str2[m-1]){
                res += str1[n-1];
                n--;
                m--;
            }else{
                if (dp[n-1][m] > dp[n][m-1]){
                    res += str1[n-1];
                    n--;
                }else{
                    res += str2[m-1];
                    m--;
                }
            }
        }
        
        while(n>0){
            res += str1[n-1];
            n--;
        }
        while(m>0){
            res += str2[m-1];
            m--;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};