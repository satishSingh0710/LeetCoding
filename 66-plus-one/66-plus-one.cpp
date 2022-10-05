class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int i = 0;
        int carry = 0;
        if (digits[i] + 1>9){
            digits[0] = 0;
            carry = 1;
            i++;
        }else if (digits[i]-'0'+1<=9){
            digits[0] = digits[i]+1;
        }
        while(carry && i<digits.size()){
            int sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum%10;
            digits[i] = sum;
            i++;
        }
        
        if (carry){digits.push_back(1);}
        reverse(digits.begin(),digits.end());
        return digits;
    }
};