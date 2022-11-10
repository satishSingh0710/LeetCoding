class Solution {
private:
    int minAns = INT_MAX, n,m;
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp){
         if (col<0 || col>=m||row>=n) return INT_MAX - 40000;
        if(row == n-1 && col>=0 && col<m){
            return matrix[row][col];
        }
       
        if (dp[row][col]!= -1) return dp[row][col];
        int left = 0, right = 0, down = 0;
        right= matrix[row][col] + solve(matrix, row+1, col+1, dp);
        left = matrix[row][col] + solve(matrix, row+1, col-1, dp);
        down =  matrix[row][col] + solve(matrix, row+1, col, dp);
        return dp[row][col]  = min(left, min(right, down));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for (int i = 0;i<m;i++){
          minAns = min(minAns,solve(matrix, 0,i,dp));
        }
        
        return minAns;
    }
};