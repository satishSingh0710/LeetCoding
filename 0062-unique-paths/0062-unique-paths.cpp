class Solution {
public:
    int dp[102][102];
    int solve(int row, int col){
        if (row == 0 && col == 0){
            return 1;
        }
        if (row<0 || col<0) return 0;
        if (dp[row][col]!= -1) return dp[row][col];
        int left =  solve(row, col-1);
        int right = solve(row-1, col);
        return dp[row][col] = left + right;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
       return solve(m-1, n-1);
    }
};