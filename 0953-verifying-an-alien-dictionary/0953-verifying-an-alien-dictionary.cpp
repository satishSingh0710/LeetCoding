class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0;i<order.size();i++){
            mp[order[i]] = i;
        }
        
        for (int i = 0;i<words.size()-1;i++){
            string word1 = words[i], word2 = words[i+1];
            int minWord = min(word1.size(), word2.size());
            bool ignore = false;
            for (int j = 0;j<minWord;j++){
                if (mp[word1[j]] < mp[word2[j]]){ignore = true; break;}
                if(mp[word1[j]]>mp[word2[j]]) return false;
            }
            if (ignore==false){
                if (word1.size()>word2.size()) return false;  
            }
          
            
        }
        
        
        return true;
        
        
    }
};