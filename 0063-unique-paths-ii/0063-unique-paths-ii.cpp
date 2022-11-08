class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>> &obstacleGrid, int row, int col){
        if (row == 0 && col == 0) {
            if (obstacleGrid[row][col] == 0) 
             return 1;
             return 0;
        }
        if (row < 0  || col < 0) return 0;
        if (obstacleGrid[row][col] == 1) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        int top = solve(obstacleGrid, row-1, col);
        int left = solve(obstacleGrid, row , col-1);
        return dp[row][col] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int n = obstacleGrid.size()-1, m = obstacleGrid[0].size()-1;
        memset(dp, -1, sizeof(dp));
        return solve(obstacleGrid, n, m);
    }
};