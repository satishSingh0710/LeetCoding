class Solution {
public:
    int solve(vector<int> &nums, int index,vector<int> &dp){
        if (index>=nums.size()) return 0;
        if (dp[index]!=-1) return dp[index];
        int jump = index+2;
        int loot = nums[index];
        while(jump<nums.size()){
           int tempLoot = nums[index] + solve(nums, jump, dp);
           loot = max(loot, tempLoot);
           jump++;
        }
        return dp[index] = loot;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int first, second;
        first = solve(nums, 0, dp);
        second = solve(nums, 1, dp);
        return max(first, second);
    }
};