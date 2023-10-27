class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        // for odd length palindromes 
        for (int i = 0;i<n;i++){
            for (int j = 0;i+j<n && i-j >= 0;j++){
                if(s[i-j] == s[i+j]){
                    dp[i-j][i+j] = 1;  
                }else{
                    break;
                }
            }
        }
        // for even length palindromes 
        for (int i = 0;i<n-1;i++){
            for (int j = 0;j<n && i-j>=0 && (i+j+1)<n;j++){
                if(s[i-j] == s[i+j+1]){
                    dp[i-j][i+j+1] = 1; 
                }else{
                    break;
                }
            }
        }
        int st = 0, ed = 0; 
        for(int i = 0;i<n;i++){
            for (int j = i;j<n;j++){
                if(dp[i][j] == 1 && j-i > ed - st){
                    ed = j; 
                    st = i; 
                }
            }
        }
        return s.substr(st, ed-st+1); 
    }
};