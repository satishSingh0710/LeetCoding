class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]<10) res.push_back(nums[i]);
            else{
                string num = to_string(nums[i]);
                for (int j = 0;j<num.size();j++){
                    res.push_back(num[j] - '0');
                }
            }
        }
        
        
        return res;
    }
};