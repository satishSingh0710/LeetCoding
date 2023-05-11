class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col, int &n, int &m,vector<vector<int>> &dp){
        if (row>=n || col>=m) return INT_MAX - 100000; 
        if (row == n-1 && col == m-1){
            return grid[row][col]; 
        }
        if (dp[row][col] != -1) return dp[row][col];
        int choice1= 0, choice2 = 0; 
        choice1 = grid[row][col] + solve(grid, row+1, col, n, m,dp); 
        choice2 = grid[row][col] + solve(grid, row, col+1, n, m, dp);
        return  dp[row][col] =   min(choice1,choice2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); \
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, 0,0,n,m, dp);
    }
};