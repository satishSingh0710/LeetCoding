class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> character(26,-1);
        int count = 0; 
        for (int i = 0;i<s.size();i++){
            if (character[s[i] - 'a'] == -1){
                character[s[i] - 'a'] = 0; count++;
            }
        }
        
        return count==26;
    }
};