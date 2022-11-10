class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        if (row == 0 && col == 0){
            return grid[row][col];
        }
        if (row<0 || col<0){
            return INT_MAX-40000;
        }
        
        if (dp[row][col] != -1){return dp[row][col];}
        long long int sum1= grid[row][col] + solve(grid, row-1, col,dp);
        long long int sum2 = grid[row][col] + solve(grid, row, col-1,dp);
        return dp[row][col] = min(sum1, sum2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n-1, m-1,dp);
    }
};