class Solution {
public:
    int minSize = INT_MAX;
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,j = 0;
        int sum = 0;
        while(j<nums.size()){
            sum+= nums[j];
           if (sum>= target){
                while(sum>=target){
                    if (sum >= target && j - i + 1<= minSize){
                        minSize = j - i +1;
                     }   
                    sum -= nums[i];
                    i++;
                }
            }
           
          
            j++;
            
        }
        return minSize==INT_MAX?0:minSize;
    }
};