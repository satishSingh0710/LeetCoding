class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(); 
        int req = n/4; 
        unordered_map<int,int> mp; 
        for (auto &i: arr){
            mp[i]++; 
        }
        for (auto &i: mp){
            if(i.second > req){return i.first;}
        }
        return -1; 
    }
};