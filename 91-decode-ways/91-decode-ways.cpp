class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.resize(101,-1);
        return solve(s,0);
    }
    
    int solve(string &s, int index)
    {
        if (index>=s.size()) return 1;
        if (dp[index] != -1) return dp[index];
        int res = 0;
        int pickOne = s[index]-'0',pickTwo;
        if (index<s.size()-1){
          pickTwo = pickOne*10 + s[index+1]-'0';     
        }
    
        if (pickOne>=1)res+=solve(s,index+1);
        if (pickTwo>=10 && pickTwo<=26) res+=solve(s,index+2);
        
        return dp[index] = res;
        
    }
};

// class Solution {
// public:int count = 0;
//     bool selectOne(string s, int index)
//     { if (s[index]!='0')return true; return false; }
    
    
//     bool selectTwo(string s, int index1, int index2)
//     {   if (index1<s.size() && index2<s.size()) {
//             if (s[index1]=='1'||s[index1]=='2'){
//                 if (s[index1]=='2' && s[index2]>='7') return false;
//                 return true;
//             }
//         }return false;
//     }
    
//     int numDecodings(string s) {
//         solve(s,0);  return count;
//         }
    
//     void solve(string s, int index)
//     {
//         if (index >= s.size()){count++; return;}
//         if (selectOne(s,index)){solve(s,index+1);}
//         if (selectTwo(s,index,index+1)){solve(s,index+2);}
//     }
    
    
// };