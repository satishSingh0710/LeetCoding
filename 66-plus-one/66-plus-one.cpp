class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
//         bool all_9 = true;
//         for (auto &i: digits){
//             if (i!=9){
//                 all_9 = false;
//             }
//         }
        
//         if (all_9){
//             digits.insert(digits.begin(),1);
//             for (auto &i: digits){
//                 i = 0;
//             }
//             digits[0] = 1;
//         }else{
            for (int i = digits.size()-1;i>=0;i--){
                digits[i]++;
                if(digits[i]==10){
                    digits[i] = 0;
                }else break;
            }
        // }
        if (digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};