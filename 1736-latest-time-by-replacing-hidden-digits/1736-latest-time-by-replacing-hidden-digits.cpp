class Solution {
public:
    string maximumTime(string time) {
        for (int i = 0;i<5;i++){
            if (time[i]=='?'){
               if (i == 0){
                   if (time[i+1] == '?'){
                       time[i] = '2'; time[i+1] = '3';
                   } else if (time[i+1]<= '3'){
                       time[i] = '2';
                   } else{
                       time[i] = '1';
                   }
               } else if (i == 1){
                   if (time[i-1] - '0'<= 1){
                       time[i] = '9';
                   }else{
                       time[i] = '3';
                   }
               } else if (i== 3){
                   if (time[i+1] == '?'){
                       time[i] = '5'; time[i+1]= '9';
                   }else {
                       time[i] = '5';
                   }
               } else if (i == 4){
                   time[i] = '9';
               }
            }
        }
        return time;
    }
};