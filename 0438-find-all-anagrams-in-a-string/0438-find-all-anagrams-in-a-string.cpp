class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> mp;
        for (auto &i: p){
            mp[i]++;
        }
        int i = 0, j = 0;
        int count = mp.size(); 
        while(j < s.size()){
            if (mp.find(s[j])!= mp.end()){
                mp[s[j]]--;
                if (mp[s[j]] == 0){
                    count--;
                }
            }
            
             if (j - i + 1 == p.size()){
                if (count == 0){
                    res.push_back(i);
                }
                if (mp.find(s[i])!= mp.end()){
                    mp[s[i]]++;
                    if (mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        
        return res;
    }
};