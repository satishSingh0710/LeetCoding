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
       
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum+1));
        
        for (int i = 0;i<nums.size();i++){
            for (int j = 0;j<=sum;j++){
                if (j==0){
                    dp[i][j] = true;
                }
                
                if (i==0 && j!=0){
                    dp[i][j] = false;
                }
            }
        }
        
        
        for (int i = 1;i<nums.size();i++){
            for (int j = 1;j<=sum;j++){
                if (nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
  
        
       return dp[nums.size()-1][sum];
      
        
    }
};