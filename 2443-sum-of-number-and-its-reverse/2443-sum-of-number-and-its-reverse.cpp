class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
       for (int i = 1;i<=num;i++){
           int n = i;
           int temp = 0;
           while(n>0){
               int x = n%10;
               temp = temp*10 +x;
               n = n/10;
           }
           
           if (i + temp == num) return true; 
       } 
        return false;
    }
};