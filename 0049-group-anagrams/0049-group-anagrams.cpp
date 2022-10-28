class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (int i = 0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        
        for (auto &i: mp){
            vector<string> temp;
            temp = i.second;
            res.push_back(temp);
        }
        
        return res;
    }
};