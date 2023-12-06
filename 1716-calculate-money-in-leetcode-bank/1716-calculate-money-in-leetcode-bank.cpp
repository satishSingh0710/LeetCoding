class Solution {
public:
    int totalMoney(int n) {
       int prevMonday = 0, prevDay = 0; 
        int day = 0,bal = 0; 
        while(day < n){
            if(day%7 == 0){
                bal += prevMonday + 1; 
                prevMonday++; 
                prevDay = prevMonday;
            }else{
                bal += prevDay+1; 
                prevDay++;
            }
            day++;
        }
        return bal; 
    }
};