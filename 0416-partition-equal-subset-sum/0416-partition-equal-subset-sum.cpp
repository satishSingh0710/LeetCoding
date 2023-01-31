class Solution {
public:
    
    bool test(vector<int> &nums, int target, vector<vector<int>> &dp, int index){
        if (index == nums.size()-1){
            return nums[index] == target;
        }
        
        if (dp[index][target] != -1)return dp[index][target];
        bool notPick = test(nums, target, dp, index+1);
        bool pick = false;
        if (nums[index]<= target){
            pick = test(nums, target - nums[index], dp, index+1);
        }
        
        return dp[index][target] = (pick || notPick);
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto &i: nums){
            sum += i;
        }
        
        if (sum % 2 != 0) return false;
        sum = sum/2;
       
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        
        return test(nums,sum, dp, 0);

        
        
    }
};