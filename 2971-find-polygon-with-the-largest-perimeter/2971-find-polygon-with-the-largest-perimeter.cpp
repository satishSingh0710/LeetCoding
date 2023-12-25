class Solution {
public:
    long long int res = INT_MIN; 
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size(); 
        vector<long long int> preSum; 
        long long int s = 0; 
        for (int i = 0;i<n;i++){
            s += nums[i]; 
            preSum.push_back(s); 
        }
        for (int i = n-1;i>=1;i--){
            long long int present = nums[i]; 
            long long int sum = preSum[i-1]; 
            if(present >= sum) continue;
            res = max((long long )res, (long long)sum + (long long)present); 
        }
        return res == INT_MIN?-1:res; 
    }
};