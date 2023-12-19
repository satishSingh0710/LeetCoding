class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());                                             vector<vector<int>> res; 
        for(int i = 0;i<nums.size();i+=3){
            vector<int> temp; 
            temp.push_back(nums[i]); 
            temp.push_back(nums[i+1]); 
            temp.push_back(nums[i+2]);
            res.push_back(temp); 
        }
        for (int i = 0;i<res.size();i++){
            if(abs(res[i][0] - res[i][1]) > k || abs(res[i][1] - res[i][2]) > k || abs(res[i][2] - res[i][0]) > k) return {}; 
        }
        return res; 
    }
};