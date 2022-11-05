class Solution {
public:
    int solve(vector<int> &nums, int index, int size, vector<int> &dp){
       
        if (index == size-1) return nums[index];
        if (index>=size) return 0;
        if(dp[index]!=-2) return dp[index];
        int pick = nums[index] + solve(nums, index+2, size,dp);
        int notPick =  solve(nums, index+1, size,dp);
        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
         vector<int> dp2(n,-2), dp1(n,-2);
        int first, second;
        first = solve(nums, 0, n-1,dp1);
        second = solve(nums, 1, n,dp2);
        return max(first, second);
    }
};