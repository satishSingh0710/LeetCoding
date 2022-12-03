class Solution {
public:
    
    static bool comp(pair<int,char> &a, pair<int,char> &b){
        if (a.first == b.first){
            return a.second>b.second;
        }
        return a.first > b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for (auto &i: s){
            mp[i]++;
        }
        
        vector<pair<int,char>> temp;
        for (auto &i: mp){
            temp.push_back({i.second, i.first});
        }
        
        sort(temp.begin(), temp.end(), comp);
        s.clear();
        for (auto &i: temp){
            int x = i.first;
            while(x--){
                s+= i.second;
            }
        }
        
        return s;
    }
};