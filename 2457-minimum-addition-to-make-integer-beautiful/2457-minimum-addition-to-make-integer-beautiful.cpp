class Solution {
private: 
    int sum (long long num){
        int res = 0;
        while(num){
            res += num %10;
            num /= 10;
        }
        return res;
    }
    
    // Day after tomorrow lena merese 
    // I'm on social media detox, by god's will. 
    // No what's app for today and tomorrow, and if there's anything important, then mail me.
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long  base = 1, number = n;
        
        while(sum(n)>target){
            n = n/10 + 1;
            base *= 10;
        }
        
        return n*base - number;
    }
};