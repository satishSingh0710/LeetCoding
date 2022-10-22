class Solution {
public:
    string res = ""; 
    int minSize = INT_MAX;
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for (auto &i: t){
            mp[i]++;
        }
        
        int count = mp.size(), i = 0,j = 0;
        
        while(j<s.size())
        {
          if (mp.find(s[j]) != mp.end())
          {
              mp[s[j]]--;
              if (mp[s[j]] == 0){
                  count--;
              }
              if (count == 0){
                  while(true){
                      if (mp.find(s[i]) == mp.end()){
                          i++; continue;
                      } else{
                          if (mp[s[i]] == 0){
                              if (j - i+1 <= minSize){
                                  minSize = j - i +1;
                                  res = s.substr(i,j-i+1); break;
                              } break;
                          }
                          mp[s[i]]++; i++;
                      }
                      
                  }
              }
          }
        
            j++;
        }
        
        return res;
    }
};