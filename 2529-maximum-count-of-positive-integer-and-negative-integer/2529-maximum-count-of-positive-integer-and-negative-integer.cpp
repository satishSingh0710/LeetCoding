class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0 ;
        for (auto &i: nums){
            if (i == 0) continue;
            if (i<0) neg++;
            else pos++;
        }
        return max(neg,pos);
    }
};