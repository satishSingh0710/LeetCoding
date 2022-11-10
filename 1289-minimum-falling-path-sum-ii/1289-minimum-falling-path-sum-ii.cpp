class Solution {
public:
   int  n,m;
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp){
         if (col<0 || col>=m||row>=n) return INT_MAX - 40000;
        if(row == n-1 && col>=0 && col<m){
            return matrix[row][col];
        }
       
        if (dp[row][col]!= INT_MAX) return dp[row][col];
        for (int i = 0;i<m;i++){
            if (i == col) continue;
            int temp = matrix[row][col] + solve(matrix, row+1, i,dp);
            dp[row][col] = min(dp[row][col], temp);
        }
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
           n = matrix.size(), m = matrix[0].size();
         int minAns = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        for (int i = 0;i<m;i++){
          minAns = min(minAns,solve(matrix, 0,i,dp));
        }
        
        return minAns;
    }
};