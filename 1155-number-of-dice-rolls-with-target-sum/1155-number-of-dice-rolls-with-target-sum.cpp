class Solution {
public: 
    int m = 1000000007; 
    #define ll long long int
    vector<vector<ll>> dp; 
    ll solve(int n, int k, int sum, int target){
        if(n == 0){
            if(sum == target){return 1;}
            return 0; 
        }
        if(dp[n][sum] != -1) return dp[n][sum]; 
        ll possible = 0; 
        for (int i = 1;i<=k;i++){
            if(sum + i <= target){
                possible += solve(n-1, k, sum + i, target); 
            }else break; 
        }
        return dp[n][sum] = possible % m; 
    }
    int numRollsToTarget(int n, int k, int target) {
       dp.resize(33, vector<ll>(1200, -1));
       return solve(n, k, 0, target); 
    }
};