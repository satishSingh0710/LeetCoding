class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> fRes;
        vector<int> res;
        solve(can, fRes, res, target, 0);
        return fRes;
    }
    
    void solve(vector<int> &can, vector<vector<int>> &fres, vector<int> &res, int target, int index){
        if (target == 0) {
            fres.push_back(res); return;
        }
       else  if (target<0) return;
        
        for (int i = index;i<can.size();i++){
            if (can[i]<=target){
                res.push_back(can[i]);
                solve(can, fres, res, target-can[i], i);
                res.pop_back();
            }
        }
    }
};