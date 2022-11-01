class Solution {
    unordered_map<string, bool> mp;
    vector<vector<int>> fres;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> res;
        string temp = "";
        solve(nums, visited,res,temp);
        // cout<<mp.size()<<endl;
        return fres;
    }
    
    void solve(vector<int> &nums, vector<bool> &visited, vector<int> &res,string &s){
        if (res.size() == nums.size()){
            if (mp.find(s)!=mp.end()) return;
            mp[s] = true;
            fres.push_back(res);
            return;
        }
        
        for (int i = 0;i<nums.size();i++){
            if (visited[i]==true) continue;
            visited[i] = true;
            res.push_back(nums[i]);
            s+= to_string(nums[i]);
            solve(nums, visited, res,s);
            s.pop_back();
            if (s.size()>0){
                if (s[s.size()-1]=='-'){
                    s.pop_back();
                }
            }
            res.pop_back();
            visited[i] = false;
        }
    }
};