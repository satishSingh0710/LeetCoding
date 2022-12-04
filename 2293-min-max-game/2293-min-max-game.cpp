class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int minni = INT_MAX;
        while(nums.size()!=1){
            n = nums.size();
            vector<int> temp(n/2);
           int  j = 0;
            for (int i = 0;i<n;i+=2){
                if (j%2==0){
                    temp[j++] = min(nums[i], nums[i+1]);
                }else{
                    temp[j++] = max(nums[i], nums[i+1]);
                }
            }
            
            nums = temp;
        }
        
        return nums[0];
    }
};