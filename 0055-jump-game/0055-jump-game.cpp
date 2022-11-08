class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minimumJumps = 0;
        for (int i = nums.size()-2;i>=0;i--){
            minimumJumps++;
            if (nums[i]>=minimumJumps){
                minimumJumps = 0;
            }
        }
        
        return minimumJumps == 0;
    }
};