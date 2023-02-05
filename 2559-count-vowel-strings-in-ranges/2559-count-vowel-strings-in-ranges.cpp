class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>res, temp;
        int prev = 0;
        temp.push_back(0);
        for (int i = 0;i<words.size();i++){
            string word = words[i];
            if (isVowel(word[0]) && isVowel(word[word.size()-1])){
                temp.push_back(prev + 1);
                prev++;
            }else{
                temp.push_back(prev);
            }
        }
        
        
        for (int i = 0;i<queries.size();i++){
            int l = queries[i][0], r = queries[i][queries[i].size()-1];
            int count = temp[r+1] - temp[l];
            
            
            res.push_back(count);
            
        }
        
        return res;
    }
};