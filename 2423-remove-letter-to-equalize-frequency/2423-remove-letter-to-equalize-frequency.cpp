class Solution {
public:
    bool equalFrequency(string word) {
        for(int i =0;i<word.size();i++){
             if (isEqual(word,i)) return true;
        }
        return false;
    }
    
    bool isEqual(string word, int i){
        word.erase(i,1);
        unordered_map<char,int> mp;
        for (int x = 0;x<word.size();x++){
            mp[word[x]]++;
        }
        int temp = mp.begin()->second;
        for (auto &x: mp){
            if (x.second!=temp) return false;
        }
        return true;
    }
};