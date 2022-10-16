class Solution {
public:
    string res = "";
      static bool comp(pair<char,int> &a, pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
     unordered_map<char,int> mp;
        for (auto &i: s){
            mp[i]++;
        }
        
        vector<pair<char,int>> v;
        for (auto  &i: mp){
            v.push_back({i.first,i.second});
        }
        
        sort(v.begin(),v.end(), comp);
        
       for (auto &i: v){
           while(i.second!=0){
               res+= i.first; i.second--;
           }
       }
        
        return res;
    }
};