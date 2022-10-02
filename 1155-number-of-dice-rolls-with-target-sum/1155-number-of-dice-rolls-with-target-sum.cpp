class Solution {
public:
    #define M 1000000007
    #define row 32
    #define col 1002
    vector<vector<int>> dp;
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(row,vector<int>(col,-1));
        return solve(n,k,target);
    }
    
    int solve(int n, int k , int target){
        if (n==0&&target == 0)return 1;
        if (n<=0||target<=0)return 0;
        if (dp[n][target]!=-1)return dp[n][target];
        int ans = 0;
        for (int i = 1;i<=k;i++){
            ans = (ans%M + solve(n-1,k,target-i)%M)%M;
        }
        return dp[n][target] = ans;
    }
};