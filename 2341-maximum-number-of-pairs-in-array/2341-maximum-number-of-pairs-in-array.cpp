class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0,leftOver;
          vector<int> res;
        int n = nums.size();
        if (n == 1){
            res.push_back(0); res.push_back(1); return res;
        }
      
        sort(nums.begin(), nums.end());
        for (int i  = 1;i<n;i++){
            if (nums[i] == nums[i-1]){
                pairs++; i++;
            }
        }
        leftOver = n - pairs * 2;
        res.push_back(pairs); res.push_back(leftOver);
        return res;
    }
};