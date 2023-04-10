class Solution {
public:
    // int solve(int amount, vector<int> &store, int index,vector<vector<int>> &dp){
    //     if (index == 0){
    //         return amount;
    //     }
    //     if (dp[index][amount] != -1) return dp[index][amount];
    //     int pick = INT_MAX, notPick = 0;
    //     if (store[index] <= amount){
    //         pick = 1 + min(solve(amount - store[index], store, index,dp), solve(amount - store[index], store, index-1,dp));
    //     }
    //     notPick = 0 + solve(amount, store, index-1,dp);
    //     // cout<<pick<<" "<<notPick<<endl;
    //     return dp[index][amount] = min(pick, notPick);
    // }
    int numSquares(int n) {
        int maxNum = floor(sqrt(n));
        vector<int> store;
        for(int i = 1;i<=maxNum;i++){
            store.push_back(i*i);
        }
        
        vector<vector<int>> dp(store.size(), vector<int>(n+1));
        for (int i = 0;i<store.size();i++){
            for (int j = 0;j<=n; j++){
                if (i == 0){
                    dp[i][j] = j;
                    continue;
                }
                int pick = INT_MAX, notPick = 0;
                if (store[i] <= j){
                    pick= 1 + min(dp[i][j - store[i]], dp[i-1][j - store[i]]);
                }
                notPick = 0 + dp[i-1][j];
                dp[i][j] = min(pick, notPick);
            }
        }
        return dp[store.size()-1][n];
        
    }
};