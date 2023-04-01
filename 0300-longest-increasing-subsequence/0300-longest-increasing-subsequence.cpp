class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1;i<nums.size();i++){
            int pos = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            if (pos == temp.size()){
                temp.push_back(nums[i]);
                continue;
            }
            temp[pos] = nums[i];
        }
        return temp.size();
    }
};