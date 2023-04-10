class Solution {
public:
    int solve(int amount, vector<int> &store, int index,vector<vector<int>> &dp){
        if (index == 0){
            return amount;
        }
        if (dp[index][amount] != -1) return dp[index][amount];
        int pick = INT_MAX, notPick = 0;
        if (store[index] <= amount){
            pick = 1 + min(solve(amount - store[index], store, index,dp), solve(amount - store[index], store, index-1,dp));
        }
        notPick = 0 + solve(amount, store, index-1,dp);
        // cout<<pick<<" "<<notPick<<endl;
        return dp[index][amount] = min(pick, notPick);
    }
    int numSquares(int n) {
        int maxNum = floor(sqrt(n));
        vector<int> storeSqrs;
        for(int i = 1;i<=maxNum;i++){
            storeSqrs.push_back(i*i);
        }
        vector<vector<int>> dp(storeSqrs.size(), vector<int>(n+1, -1));
        return solve(n, storeSqrs, storeSqrs.size()-1, dp);
        
    }
};