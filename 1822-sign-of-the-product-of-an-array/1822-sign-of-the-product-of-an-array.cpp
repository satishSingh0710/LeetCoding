class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNeg = 0;
        for (auto &i: nums){
            if (i == 0) return 0;
            if (i<0) countNeg++;
        }
        
        if (countNeg%2==0) return 1;
        return -1;
    }
};