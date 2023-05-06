class Solution {
public:
    int M = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        int l = 0, r = nums.size()-1;
        vector<int> preTwo;
        preTwo.push_back(1);
        for (int i = 1;i<nums.size();i++){
            int newNum = (preTwo.back()%M * 2)%M;
            preTwo.push_back(newNum);
        }
        long long int answer = 0; 
        while(l<=r){
            int currSum = nums[l] + nums[r];
            if(currSum>target){
                r--; continue;
            }else{
                answer = (answer%M + preTwo[r-l]%M)%M;
                l++;
            }
        }
        return answer;
    }
};