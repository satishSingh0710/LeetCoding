class Solution {
int n, m;
int solve(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if (col1 < 0 || col2<0 || col1>= m || col2>=m) return -1e6;
    if (row == n-1){
        if (col1 == col2){return grid[row][col2];}
        else{
            return grid[row][col1] + grid[row][col2];
        }
    }
    if (dp[row][col1][col2] != -1)return dp[row][col1][col2];
    int maxxi = INT_MIN;
    for (int i = -1;i<=1;i++){
        for (int j  = -1;j<=1;j++){
            int newCol1, newCol2,val = 0;
            newCol1 = col1 + i; newCol2 = col2 + j;
            if (col1 == col2){val = grid[row][col1];}
            else{
                val = grid[row][col1] + grid[row][col2];
            }
            val += solve(row+1, newCol1, newCol2, grid, dp);
             maxxi = max(maxxi, val);
            }
        }
     return dp[row][col1][col2] = maxxi;
    }
   

public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0,0,m-1, grid,dp);
        
    }
};