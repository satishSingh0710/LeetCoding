class Solution {
public:
    int partitionString(string s) {
       unordered_set<char> setHaiBoss;
        int count = 0;
        for (int i = 0;i<s.size();i++){
            if (setHaiBoss.find(s[i])!= setHaiBoss.end()){
                count++;
                setHaiBoss.clear();
                setHaiBoss.insert(s[i]);
            }else{
                setHaiBoss.insert(s[i]);
            }
        }
        
        return count+1;
    }
};