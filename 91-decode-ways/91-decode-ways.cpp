class Solution {
public:
    // int ans=0;
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        vector<int> dp(101,-1);
        return solve(s,0,dp);
    }
    
    int solve(string &s, int index, vector<int> &dp){
        if (index>=s.size()) return 1;
        if (dp[index]!=-1)return dp[index];
        int ans = 0;
        
        int pickOne = s[index] - '0', pickTwo = 0;
        if (index<s.size()-1){
            if (pickOne>=1){
                pickTwo = pickOne*10 + s[index+1]-'0'; 
            }else return 0;
        }
        
        if (pickOne>=1) ans+= solve(s,index+1,dp);
        else return 0;
        if (pickTwo>=10 && pickTwo<=26) ans+= solve(s,index+2,dp);
        return dp[index] = ans;
        
    }
};