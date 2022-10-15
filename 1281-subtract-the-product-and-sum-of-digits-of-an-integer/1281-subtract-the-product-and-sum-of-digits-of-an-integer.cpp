class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, multi = 1;
        while(n>0){
            sum += n%10;
            multi*= n%10;
            n = n/10;
        }
        return multi - sum;
    }
};