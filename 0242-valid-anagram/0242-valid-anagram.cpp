class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> characters(26,0);
        for (auto &i: s){
            characters[i - 'a']++;
        }
        
        for (auto &i: t){
            characters[i-'a']--;
        }
        
        for (auto &i: characters){
            if (i>0 || i<0) return false;
        } return true;
    }
};