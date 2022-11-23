class Solution {
public:
    int solve (vector<vector<int>> &triangle, vector<vector<int>> &dp, int row, int col){
        if (row == triangle.size()-1){
            return triangle[row][col];
        }

        if (dp[row][col]!= -1){
            return dp[row][col];
        }
        
        int same = triangle[row][col] + solve(triangle, dp, row+1, col);
        int next = triangle[row][col] + solve(triangle, dp, row+1, col+1);
        return  dp[row][col] = min(same, next);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[0].size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(triangle, dp, 0,0);
    }
};