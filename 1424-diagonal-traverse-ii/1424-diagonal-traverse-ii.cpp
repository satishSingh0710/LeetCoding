class Solution {
public:
    static bool comp(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
        if(a.first == b.first){
            return a.second.first > b.second.first;
        }
        return a.first < b.first; 
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>> vpp; 
        for (int i = 0;i<nums.size();i++){
            for (int j = 0;j<nums[i].size();j++){
                int sum = i + j; 
                int row = i; 
                int val = nums[i][j]; 
                vpp.push_back({sum, {row, val}}); 
            }
        }
        sort(vpp.begin(), vpp.end(), comp); 
        vector<int> res; 
        for (auto &i: vpp){
            res.push_back(i.second.second); 
        }
        return res; 
    }
};