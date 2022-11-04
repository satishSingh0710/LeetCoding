class Solution {
public:
    int solve(vector<int> &cost, int index, vector<int> &dp){
        if (index>cost.size()-1) return 0;
        if (dp[index]!=-1) return dp[index];
        int one = INT_MAX, two = INT_MAX;
        one = cost[index] + solve(cost, index+1,dp);
        if (index<=cost.size()-2){
            two = cost[index] + solve(cost, index+2, dp);
        }
        return dp[index] =min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int zero = solve(cost, 0,dp);
        int first = solve(cost, 1,dp);
        return min(zero, first);
    }
};