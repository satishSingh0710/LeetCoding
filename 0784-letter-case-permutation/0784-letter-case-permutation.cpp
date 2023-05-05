class Solution {
public: 
    unordered_set<string> tempRes;
    void solve(string s, int index){
      
      tempRes.insert(s);
      if(index>=s.size()) return;
      if(s[index]<'0' || s[index]>'9'){
      s[index] = toupper(s[index]);
      solve(s,index+1);
      s[index] = tolower(s[index]);
      solve(s, index+1);
      }else{
          solve(s,index+1);
      }
     
    }
    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        vector<string> res;
        for(auto &i: tempRes){
          res.push_back(i);
        }
        return res;
    }
};