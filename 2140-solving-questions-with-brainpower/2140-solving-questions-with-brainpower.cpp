class Solution {
public:
    long long int solve(vector<vector<int>> &questions, int index, vector<long long int> &dp){
        if (index >= questions.size()){
            return 0; 
        }
        if (dp[index] != -1) return dp[index];
        long long int solvee = 0, dontSolve = 0; 
      
        solvee = questions[index][0] + solve(questions, index + questions[index][1] + 1,dp);
        dontSolve = 0 + solve(questions, index+1,dp);
        return dp[index] = max(solvee, dontSolve);
       
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long int> dp(questions.size(), -1); 
         return solve(questions, 0, dp);   
    }
};