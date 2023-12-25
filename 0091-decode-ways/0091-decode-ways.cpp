class Solution {
public:
    vector<int> dp;
    int solve(string s, int idx){
        if(idx == s.size()-1 && s[idx] != '0') return 1; 
        if(idx >= s.size()) return 1; 
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx]; 
        int ways = 0; 
        if(s[idx] == '2'){
            if(s[idx+1] <= '6'){
               ways += max(ways, solve(s,idx+1) + solve(s, idx + 2));    
            }else{
                ways += max(ways,solve(s, idx + 1)); 
            }
        }else if(s[idx] == '1'){
            ways += max(ways,solve(s, idx + 1) + solve(s, idx + 2)); 
        }else{
            ways += max(ways, solve(s, idx + 1)); 
        }
        
        return  dp[idx] = ways; 
    }
    int numDecodings(string s) {
        dp.resize(101, -1); 
        int ans = solve(s, 0); 
        return ans <= 0?0:ans;
    }
};