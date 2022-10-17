class Solution {
public:
    bool isHappy(int n) {
        unordered_map<char, int>  mp;
        
        while (n!=1){
            if (mp.find(n)== mp.end()) mp[n]++; 
            else return false;
          int sum = 0;
          int x = n;
            while(n>0){
                sum += pow(n%10,2);
                n = n/10;
            }
         n = sum;
        }
        
        return true;
    }
};