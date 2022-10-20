class Solution {
public:
    string intToRoman(int num) {
        
        // maa ki chut is question ki
       vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res = "";
       for (int i = 0;i<symbol.size();i++){
           while(num>=val[i]){
               res+= symbol[i];
               num -= val[i];
           }
       }
        
        return res;
        
    }
};