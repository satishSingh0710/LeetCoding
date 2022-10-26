class Solution {
public:
    int count = 0;
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp;
        
        for (int i = 0;i<nums.size();i++){
            sum += nums[i];
            if (sum == k) count++;
            int findNum =  sum - k;
          
            if (mp.find(findNum) != mp.end()){count+= mp[findNum];}
            mp[sum]++;
        }

        return count;
    }
};