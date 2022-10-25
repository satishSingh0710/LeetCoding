class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,bool> mp;
        int count = 0;
        for (int i = 0;i<jewels.size();i++){
            mp[jewels[i]] = true;
        }
        
        for (int i = 0;i<stones.size();i++){
            if (mp[stones[i]] == true) count++;
        }
        
        return count;
    }
};