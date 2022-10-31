class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int i= 0, j = nums.size()-1;
         vector<int> twopower{1}; //precompute pow of 2 
        
        for(int i = 0;i<nums.size();i++){
            twopower.push_back((twopower.back()*2)%1000000007);
        }
        while(i<=j){
            int sum = nums[i] + nums[j];
            if (sum > target){
                j--; continue;
            } 
            int expo = j - i;
            res =(res +twopower[expo])%1000000007;
            i++;
        }
        
        return res;
    }
};