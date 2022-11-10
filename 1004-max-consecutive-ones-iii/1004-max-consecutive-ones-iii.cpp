class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  i = 0, j = 0, longest = INT_MIN, zeroes = 0;
        while(j<nums.size()){
            if (nums[j] ==0) zeroes++;
            while(zeroes>k){
                if(nums[i] ==0){
                   zeroes--;
                } i++;
            }
            
            longest = max(longest, j - i +1);
            j++;
        }
        
        return longest;
    }
};