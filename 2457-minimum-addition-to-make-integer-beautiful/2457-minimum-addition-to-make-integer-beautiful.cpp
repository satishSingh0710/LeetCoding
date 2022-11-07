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