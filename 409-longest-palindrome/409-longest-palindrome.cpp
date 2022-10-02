class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        for (int i = 0;i<n;i++){
            mp[s[i]]++;
        }
       int evenCount = 0, oddCount = 0,odd = 0;
        for (auto &i: mp){
            if (i.second%2==0){
                evenCount+= i.second;
            }else{
               oddCount+= i.second; odd++;
            }
        }
        if (n%2==0){
            if (odd>=1){
                return (evenCount + oddCount - odd +1);
            }else return evenCount;
        }else{
            if (odd>1)
           return (oddCount + evenCount - odd+1);
            if (odd==1)
            return oddCount+evenCount;
        }
        return 0;
    }
};