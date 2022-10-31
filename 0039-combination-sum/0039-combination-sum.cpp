class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(candidates, target, result, 0, temp);
        return result;
    }
    
    void solve(vector<int>& candidates, int target,vector<vector<int>> &result, int index, vector<int> temp){
        if (index == candidates.size()){
            if (target == 0){
                result.push_back(temp); 
            } 
            return;
        }
        
        if (candidates[index]<=target){
            temp.push_back(candidates[index]);
            solve(candidates, target - candidates[index], result, index, temp);
            temp.pop_back();
        }
         
        solve(candidates, target, result, index+1, temp);
    }
};