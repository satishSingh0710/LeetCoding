class Solution {
public:
    // int solve(int n, vector<int> &dp){
    //     if (n == 0) return 0;
    //     if (dp[n] != -1) return dp[n];
    //     int res = INT_MAX;
    //     for (int i = 1;i*i<=n;i++){
    //           res = min(res, 1 + solve(n-i*i,dp));
    //     }
    //     return dp[n] = res;
    // }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        for (int i = 0;i<=n;i++){
            if (i == 0) dp[i] = 0;
            else{
                int res = INT_MAX;
                for (int j = 1;j*j<=i;j++){
                    res = min(res, 1 + dp[i - j*j]);
                }
                dp[i] = res;
            }
        }
        return dp[n];
    }
};