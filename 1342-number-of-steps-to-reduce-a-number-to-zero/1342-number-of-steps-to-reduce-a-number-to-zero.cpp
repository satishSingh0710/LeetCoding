class Solution {
public:
    int count = 0;
    int numberOfSteps(int num) {
        return solve(num);
    }
    
    int solve(int num){
        if (num ==0) return count;
        count++;
        if (num%2==0) return solve(num/2);
        else return solve(num-1);
    }
};