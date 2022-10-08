class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n<3) return 0;
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        
        for (int i = 0;i<n-2;i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, h = n-1;
            
            while(l<h){
                int sum = nums[i] + nums[l] + nums[h];
                if (sum == target) return sum;
                if (abs(target - sum) < abs(target - closest)){
                    closest = sum;
                }
                
                if (sum>target) h--;
                else l++;
            }
        }
        
        return closest;
    }
        
     
};